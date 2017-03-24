#include "testcoordinate.hpp"

bool coordinate_toString(string fname)
{
	ofstream output(fname.c_str(), ios::app);

	Coordinate origin(0.0, 0.0);
	Coordinate zeroOne(0.0, 1.0);
	Coordinate oneZero(1.0, 0.0);

	UnitTest<string> test(fname.c_str());

	test.assertEquals(origin.toString(), "(0.000000,0.000000)", "origin.toString() != (0.000000,0.000000)");
	test.assertEquals(zeroOne.toString(), "(0.000000,1.000000)", "zeroOne.toString() != (0.000000,1.000000)");
	test.assertEquals(oneZero.toString(), "(1.000000,0.000000)", "oneZero.toString() != (1.000000,0.000000)");

	return test.passed();
}
