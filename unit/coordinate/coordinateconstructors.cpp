#include "testcoordinate.hpp"

bool coordinate_constructors(string fname)
{
	UnitTest<double> test(fname.c_str());

	test.assertEquals(test.toString(), "(0.0,0.0)");

	return test.passed();
}



//	TODO:
//
//
//
