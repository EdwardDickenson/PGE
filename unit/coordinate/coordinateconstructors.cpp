#include "testcoordinate.hpp"

bool coordinate_constructors(string fname)
{
	UnitTest<string> test(fname.c_str());
	Coordinate origin;
	Coordinate oneOne(1.0, 1.0);

	test.assertEquals(origin.toString(), "(0.000000,0.000000)", "Coordinate not zero at creation");
	test.assertEquals(oneOne.toString(), "(1.000000,1.000000)", "Coordinate not one at creation");

	return test.passed();
}



//	TODO:
//
//
//
