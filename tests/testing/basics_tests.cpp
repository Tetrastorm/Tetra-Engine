/*
 * Valentin DIARD, 2020
 *
 * Project:     Tetra Engine
 * License:     MIT License
 *
 * File:        basics_tests.cpp
 * Description: Check if tests work fine.
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>

Test(BLABLA, lol, .timeout=0.5f)
{
    cr_assert(true);
}
