#!/usr/bin/env bash
##
## Valentin DIARD, 2020
##
## License:     MIT License
##
## File:        install_depends.sh
## Description: Install all dependecies need by the software.
##

#
# Check if the script run as root
#
if [ "$EUID" -ne 0 ] ; then
    echo -e "ERROR: Please run as root the script."
    exit 1;
fi

#
# Check the linux distrib and install depends
#
if grep -q 'Ubuntu' /proc/version ; then
    # Install GNU Make and Clang
    apt-get install build-essential clang

    # Install OpenGL and Vulkan lib
    apt-get install libglfw3-dev libglew-dev libxinerama-dev libxi-dev libvulkan-dev libgl1-mesa-dev
elif -f "/etc/redhat-release" ; then
    dnf install glew-devel glfw-devel libXinerama-devel libXrandr-devel libXi-devel vulkan-devel
else
    echo -e "ERROR: This script don't support your OS."
    exit 1;
fi
