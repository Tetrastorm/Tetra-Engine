#!/usr/bin/env bash
##
## Valentin DIARD, 2020
##
## License:     MIT License
##
## File:        install_cmake.sh
## Description: Install CMake compilation tool.
##

version=3.17
build=3

#
# Check if the script run as root
#
if [ "$EUID" -ne 0 ] ; then
    echo -e "ERROR: Please run as root the script."
    exit 1;
fi

mkdir tmp
cd tmp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/

./bootstrap
make -j$(nproc)
make install
