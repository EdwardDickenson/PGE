#ifndef TESTRGBCOLOR_HPP
#define TESTRGBCOLOR_HPP

#include "../unit.hpp"

bool test_rgb_constructors(string fname);
bool test_rgb_mutators(string fname);
bool test_rgb_accessors(string fname);
bool test_rgb_toString(string fname);

#endif // TESTRGBCOLOR_HPP



//	TODO:
//	Write a unit test class which helps to cut down on the amount of copy paste code in the unit tests.
//	Said class should be able to: log failed tests, the time that the occurred, the output of the test and the expected result into a file
//
//
