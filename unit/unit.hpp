#ifndef UNIT_HPP
#define UNIT_HPP

#pragma once

#include "../deps.hpp"
#include "../geometry/geometry.hpp"
#include "../types/types.hpp"
#include "../draw.hpp"

template<class T>
class UnitTest
{
private:
	unsigned long long nTests;
	unsigned long long nFailed;
	ofstream output;
	clock_t curr_time;
	bool passedAll;	//	Passed all tests

public:

	UnitTest(string fname);
	~UnitTest();

	bool assertEquals(T a, T b, string expected);
	bool assertNotEquals(T a, T b, string expected);
	bool passed();
	unsigned long long tested();	//	Not as much fun as it probably sounds like it should be
	unsigned long long failed();
};

template<class T>
UnitTest<T>::UnitTest(string fname)
{
	nTests = 0;
	nFailed = 0;
	output.open(fname.c_str(), ios::app);
	passedAll = true;
}

template<class T>
UnitTest<T>::~UnitTest()
{
	output.close();
}

template<class T>
bool UnitTest<T>::assertEquals(T a, T b, string expected)
{
	++nTests;
	if(a != b)
	{
		curr_time = clock();
		++nFailed;
		output << setprecision(4) << fixed << (((double)curr_time) / CLOCKS_PER_SEC) << "," << nTests << "," << expected << endl;
		passedAll = false;
		return false;
	}

	return true;
}

template<class T>
bool UnitTest<T>::assertNotEquals(T a, T b, string expected)
{
	++nTests;
	if(a == b)
	{
		curr_time = clock();
		++nFailed;
		output << setprecision(4) << fixed << (((double)curr_time) / CLOCKS_PER_SEC) << "," << nTests << "," << expected << endl;
		passedAll = false;
		return false;
	}

	return true;
}

template<class T>
bool UnitTest<T>::passed()
{
	return passedAll;
}

template<class T>
unsigned long long UnitTest<T>::tested()
{
	return nTests;
}

template<class T>
unsigned long long UnitTest<T>::failed()
{
	return nFailed;
}

#endif // UNIT_HPP

//	TODO:
//	We already have an "expected" column for the output file, now include an "actual" column
//
//
//
