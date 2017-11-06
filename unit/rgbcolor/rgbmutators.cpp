#include "testrgbcolor.hpp"

bool rgb_mutators(string fname)
{
	ofstream output(fname.c_str(), ios::app);

	rgbColor color;
	rgbColor generated;
	rgbColor black(0, 0, 0);

	UnitTest<int> test(fname.c_str());

	for(int i = 0; i < 255; ++i)
	{
		for(int j = 0; j < 255; ++j)
		{
			for(int k = 0; k < 255; ++k)
			{
				generated.setColor(i, j, k);

				test.assertEquals(generated.red(), (double(i) / 255), "generated.red() != (double(" + to_string((double(i) / 255)) + "/ 255))");
				test.assertEquals(generated.green(), (double(j) / 255), "generated.green() != (double(" + to_string((double(j) / 255)) + "/ 255))");
				test.assertEquals(generated.blue(), (double(k) / 255), "generated.blue() != (double(" + to_string((double(k) / 255)) + "/ 255))");
				test.assertEquals(generated.HTMLRed(), i, "generated.HTMLRed() != " + to_string(i));
				test.assertEquals(generated.HTMLGreen(), j, "generated.HTMLGreen() != " + to_string(j));
				test.assertEquals(generated.HTMLBlue(), k, "generated.HTMLBlue() != " + to_string(k));
			}
		}
	}

	color.setRed(0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setGreen(0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setBlue(0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setHTMLRed(255);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setHTMLGreen(255);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setHTMLBlue(255);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(0.0, 0.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setRed(1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setGreen(1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setBlue(1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setHTMLRed(0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setHTMLGreen(0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() ! = 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setHTML(255);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLBlue() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(-1.0, 0.0, 0.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setHTML(65280);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLBlue() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, -1.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setHTML(16711680);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLBlue() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, 0.0, -1.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(0.0, 0.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(2.0, 0.0, 0.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, 0.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, 2.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, 0.0, 0.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0.0, 0.0, 2.0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(-255, 0, 0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, -255, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, -255);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(1024, 0, 0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 1024, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setColor(0, 0, 1024);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	color.setColor(0, 0, 0);
	test.assertEquals(color.red(), 0.0, "color.red() != 0.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 0, "color.HTMLRed() != 0");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setRed(-1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 0.0, "color.green() != 0.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 0, "color.HTMLGreen() != 0");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setGreen(-1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 0.0, "color.blue() != 0.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 0, "color.HTMLBlue() != 0");

	color.setBlue(-1.0);
	test.assertEquals(color.red(), 1.0, "color.red() != 1.0");
	test.assertEquals(color.green(), 1.0, "color.green() != 1.0");
	test.assertEquals(color.blue(), 1.0, "color.blue() != 1.0");
	test.assertEquals(color.HTMLRed(), 255, "color.HTMLRed() != 255");
	test.assertEquals(color.HTMLGreen(), 255, "color.HTMLGreen() != 255");
	test.assertEquals(color.HTMLBlue(), 255, "color.HTMLBlue() != 255");

	output << "#Number of tests: " << test.tested() << endl;
	output << "#Number failed: " << test.failed() << endl;

	output.close();

	return test.passed();
}



//	TODO:
//
//
//
