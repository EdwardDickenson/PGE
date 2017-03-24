#include "testrgbcolor.hpp"

bool rgb_toString(string fname)
{
	ofstream output(fname.c_str(), ios::app);

	rgbColor color;
	rgbColor black(0, 0, 0);
	rgbColor half(127, 127, 127);
	rgbColor zeroHalfOne(0, 127, 255);
	rgbColor oneHalfZero(255, 127, 0);
	rgbColor fromString(zeroHalfOne.toString());

	UnitTest<string> test(fname.c_str());

	test.assertEquals(color.toString(), "#ffffff", "color.toString() != \"#ffffff\"");
	test.assertEquals(black.toString(), "#000000", "black.toString() != \"#000000\"");
	test.assertEquals(half.toString(), "#7f7f7f", "half.toString() != \"#7f7f7f\"");
	test.assertEquals(zeroHalfOne.toString(), "#007fff", "zeroHalfOne.toString() != \"#007fff\"");
	test.assertEquals(oneHalfZero.toString(), "#ff7f00", "OneHalfZero.toString() != \"#ff7f00\"");
	test.assertEquals(fromString.toString(), "#007fff", "fromString.toString() != \"#007fff\"");
	oneHalfZero.setString(zeroHalfOne.toString());
	test.assertEquals(oneHalfZero.toString(), "#007fff", "OneHalfZero.toString() != \"#007fff\"");

	output << "#Number of tests: " << test.tested() << endl;
	output << "#Number failed: " << test.failed() << endl;

	output.close();
	return test.passed();
}



//	TODO:
//
//
//
