#include "testcoordinate.hpp"

bool coordinate_mutators(string fname)
{
	UnitTest<int> test(fname.c_str());
	Coordinate origin(0.0, 0.0);

	//origin.setX(1);
	//origin.setY(1);

	//testAssert(origin.getX(), 1, "Coordinate x value is not as it was set for empty constructor");
	//testAssert(origin.getY(), 1, "Coordinate y value is not as it was set for empty constructor");
	//testAssert(int(origin.getRelX()), 0, "Coordinate relative x value is not zero for an undefined dimension");
	//testAssert(int(origin.getRelY()), 0, "Coordinate relative y value is not zero for an undefined dimension");



	return true;
}



//	TODO:
//
//
//
