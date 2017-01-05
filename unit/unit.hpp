#ifndef UNITS_HPP
#define UNITS_HPP

#include "../deps.hpp"
#include "../geometry/geometry.hpp"
#include "../types/types.hpp"
#include "../draw.hpp"

extern unsigned long long ntests; // Number Of tests (total)
extern unsigned long long nfailed; // Number of test which have failed

#endif // UNITS_HPP

//	TODO:
//	Write a unit test class which helps to cut down on the amount of copy paste code in the unit tests.
//	Said class should be able to: log failed tests, the time that the occurred, the output of the test and the expected result into a file
//
//
