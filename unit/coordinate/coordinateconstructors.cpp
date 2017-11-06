#include "testcoordinate.hpp"

bool coordinate_constructors(string fname)
{
	UnitTest<int> test(fname.c_str());
	Coordinate origin;
	//Coordinate oneOne(1, 1);

	//est.assertEquals(origin.getX(), 0, "X coordinate not 0 at start");
	//test.assertEquals(origin.getY(), 0, "Y coordinate not 0 at start");
	//test.assertEquals(oneOne.getX(), 1, "X coordinate not 1 for Coordinate(int, int) ");
	//test.assertEquals(oneOne.getY(), 1, "Y coordinate not 1 for Coordinate(int, int) ");

	return test.passed();
}


//	TODO:
//
//
//
