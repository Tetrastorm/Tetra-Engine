/*
 * Valentin DIARD, 2020
 *
 * Project:     Tetra Engine
 * License:     MIT License
 *
 * File:        report_hock.cpp
 * Description: Help to get extra information about a crash on testing process.
*/

#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <iostream>

ReportHook(TEST_CRASH)(struct criterion_test_stats *test)
{
    std::cerr << "---------------------------------------------------------" << std::endl
              << "\x1b[31m\t\t\tTest Crashed\x1b[0m" << std::endl
              << "---------------------------------------------------------" << std::endl
              << "- File:\t\t\t" << test->file << std::endl
              << "- Test:\t\t\t" << test->test->name << std::endl
              << "- Category:\t\t" << test->test->category << std::endl
              << "- Have passed:\t\t" << test->passed_asserts << "\tTest(s)" << std::endl
              << "- Have failed:\t\t" << test->failed_asserts << "\tTest(s)" << std::endl
              << "- Exit code:\t\t" << test->exit_code << std::endl
              << "- Signal:\t\t" << test->signal << "\t" << strsignal(test->signal) << std::endl
              << "- Have timed_out:\t" << test->timed_out << std::endl
              << "---------------------------------------------------------" << std::endl;
}