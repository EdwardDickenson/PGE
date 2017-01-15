#include "testrgbcolor.hpp"

bool test_rgb_constructors(string fname)
{
	ofstream output(fname.c_str(), ios::app);

	rgbColor color;
	rgbColor black(0.0, 0.0, 0.0);
	rgbColor white(1.0, 1.0, 1.0);
	rgbColor blackHTML(0, 0, 0);
	rgbColor whiteHTML(255, 255, 255);
	rgbColor maxRed(1.0, 0.0, 0.0);
	rgbColor maxGreen(0.0, 1.0, 0.0);
	rgbColor maxBlue(0.0, 0.0, 1.0);
	rgbColor maxHTMLRed(255, 0, 0);
	rgbColor maxRedGreen(1.0, 1.0, 0.0);
	rgbColor maxRedBlue(1.0, 0.0, 1.0);
	rgbColor maxGreenBlue(0.0, 1.0, 1.0);
	rgbColor maxHTMLGreen(0, 255, 0);
	rgbColor maxHTMLBlue(0, 0, 255);
	rgbColor maxHTMLRedBlue(255, 0, 255);
	rgbColor maxHTMLRedGreen(255, 255, 0);
	rgbColor maxHTMLGreenBlue(0, 255, 255);
	rgbColor negativeRed(-1.0, 0.0, 0.0);
	rgbColor negativeGreen(0.0, -1.0, 0.0);
	rgbColor negativeBlue(0.0, 0.0, -1.0);
	rgbColor negativeHTMLRed(-255, 0, 0);
	rgbColor negativeHTMLGreen(0, -255, 0);
	rgbColor negativeHTMLBlue(0, 0, -255);
	rgbColor tooBigRed(2.0, 0.0, 0.0);
	rgbColor tooBigGreen(0.0, 2.0, 0.0);
	rgbColor tooBigBlue(0.0, 0.0, 2.0);
	rgbColor tooBigHTMLRed(1024, 0, 0);
	rgbColor tooBigHTMLGreen(0, 1024, 0);
	rgbColor tooBigHTMLBlue(0, 0, 1024);
	rgbColor half(127, 127, 127);
	rgbColor fromMask(half.HTML());

	UnitTest<int> test(fname.c_str());

	//	Note that these loops generate thousands tests
	for(int i = 0; i < 255; ++i)
	{
		for(int j = 0; j < 255; ++j)
		{
			for(int k = 0; k < 255; ++k)
			{
				rgbColor generated(i, j, k);

				test.assertEquals(generated.red(), (double(i) / 255), "generated.red() != (double(i) / 255)");
				test.assertEquals(generated.green(), (double(j) / 255), "generated.green() != (double(j) / 255)");
				test.assertEquals(generated.blue(), (double(k) / 255), "generated.blue() != (double(k) / 255)");
				test.assertEquals(generated.HTMLRed(), i, "generated.HTMLRed() != i");
				test.assertEquals(generated.HTMLGreen(), j, "generated.HTMLRed() != j");
				test.assertEquals(generated.HTMLBlue(), k, "generated.HTMLRed() != k");
			}
		}
	}

	test.assertEquals(fromMask.red(), (double(127) / 255), "fromMask.red() != (double(127) / 255)");
	test.assertEquals(fromMask.green(), (double(127) / 255), "fromMask.green() != (double(127) / 255)");
	test.assertEquals(fromMask.blue(), (double(127) / 255), "fromMask.blue() != (double(127) / 255)");
	test.assertEquals(fromMask.HTMLRed(), 127, "fromMask.HTMLRed() != 127");
	test.assertEquals(fromMask.HTMLGreen(), 127, "fromMask.HTMLGreen() != 127");
	test.assertEquals(fromMask.HTMLBlue(), 127, "fromMask.HTMLBlue() != 127");
	test.assertEquals(half.red(), (double(127) / 255), "half.red() != (double(127) / 255)");
	test.assertEquals(half.green(), (double(127) / 255), "half.green() != (double(127) / 255)");
	test.assertEquals(half.blue(), (double(127) / 255), "half.blue() != (double(127) / 255)");
	test.assertEquals(half.HTMLRed(), 127, "half.HTMLRed() != 127");
	test.assertEquals(half.HTMLGreen(), 127, "half.HTMLGreen() != 127");
	test.assertEquals(half.HTMLBlue(), 127, "half.HTMLBlue() != 127");
	test.assertEquals(tooBigHTMLRed.red(), 1.0, "tooBigHTMLRed.red() != 1.0");
	test.assertEquals(tooBigHTMLRed.green(), 0.0, "tooBigHTMLRed.green() != 0.0");
	test.assertEquals(tooBigHTMLRed.blue(), 0.0, "tooBigHTMLRed.blue() != 0.0");
	test.assertEquals(tooBigHTMLRed.HTMLRed(), 255, "tooBigHTMLRed.HTMLRed() != 255");
	test.assertEquals(tooBigHTMLRed.HTMLGreen(), 0, "tooBigHTMLRed.HTMLGreen() != 0");
	test.assertEquals(tooBigHTMLRed.HTMLBlue(), 0, "tooBigHTMLRed.HTMLBlue() != 0");
	test.assertEquals(tooBigHTMLGreen.red(), 0.0, "tooBigHTMLGreen.red() != 0.0");
	test.assertEquals(tooBigHTMLGreen.green(), 1.0, "tooBigHTMLGreen.green() != 1.0");
	test.assertEquals(tooBigHTMLGreen.blue(), 0.0, "tooBigHTMLGreen.blue() != 0.0");
	test.assertEquals(tooBigHTMLGreen.HTMLRed(), 0, "tooBigHTMLGreen.HTMLRed() != 0");
	test.assertEquals(tooBigHTMLGreen.HTMLGreen(), 255, "tooBigHTMLGreen.HTMLGreen() != 255");
	test.assertEquals(tooBigHTMLGreen.HTMLBlue(), 0, "tooBigHTMLGreen.HTMLBlue() != 0");
	test.assertEquals(tooBigHTMLBlue.red(), 0.0, "tooBigHTMLBlue.red() != 0.0");
	test.assertEquals(tooBigHTMLBlue.green(), 0.0, "tooBigHTMLBlue.green() != 0.0");
	test.assertEquals(tooBigHTMLBlue.blue(), 1.0, "tooBigHTMLBlue.blue() != 1.0");
	test.assertEquals(tooBigHTMLBlue.HTMLRed(), 0, "tooBigHTMLBlue.HTMLRed() != 0");
	test.assertEquals(tooBigHTMLBlue.HTMLGreen(), 0, "tooBigHTMLBlue.HTMLGreen() != 0");
	test.assertEquals(tooBigHTMLBlue.HTMLBlue(), 255, "tooBigHTMLBlue.HTMLBlue() != 255");
	test.assertEquals(tooBigRed.red(), 1.0, "tooBigRed.red() != 1.0");
	test.assertEquals(tooBigRed.green(), 0.0, "tooBigRed.green() != 0.0");
	test.assertEquals(tooBigRed.blue(), 0.0, "tooBigRed.blue() != 0.0");
	test.assertEquals(tooBigRed.HTMLRed(), 255, "tooBigRed.HTMLRed() != 255");
	test.assertEquals(tooBigRed.HTMLGreen(), 0, "tooBigRed.HTMLGreen() != 0");
	test.assertEquals(tooBigRed.HTMLBlue(), 0, "tooBigRed.HTMLBlue() != 0");
	test.assertEquals(tooBigGreen.red(), 0.0, "tooBigGreen.red() != 0.0");
	test.assertEquals(tooBigGreen.green(), 1.0, "tooBigGreen.green() != 1.0");
	test.assertEquals(tooBigGreen.blue(), 0.0, "tooBigGreen.blue() != 0.0");
	test.assertEquals(tooBigGreen.HTMLRed(), 0, "tooBigGreen.HTMLRed() != 0");
	test.assertEquals(tooBigGreen.HTMLGreen(), 255, "tooBigGreen.HTMLGreen() != 255");
	test.assertEquals(tooBigGreen.HTMLBlue(), 0, "tooBigGreen.HTMLBlue() != 0");
	test.assertEquals(tooBigBlue.red(), 0.0, "tooBigBlue.red() != 0.0");
	test.assertEquals(tooBigBlue.green(), 0.0, "tooBigBlue.green() != 0.0");
	test.assertEquals(tooBigBlue.blue(), 1.0, "tooBigBlue.blue() != 1.0");
	test.assertEquals(tooBigBlue.HTMLRed(), 0, "tooBigBlue.HTMLRed() != 0");
	test.assertEquals(tooBigBlue.HTMLGreen(), 0, "tooBigBlue.HTMLGreen() != 0");
	test.assertEquals(tooBigBlue.HTMLBlue(), 255, "tooBigBlue.HTMLBlue() != 255");
	test.assertEquals(negativeHTMLRed.red(), 1.0, "negativeHTMLRed.red() != 1.0");
	test.assertEquals(negativeHTMLRed.green(), 0.0, "negativeHTMLRed.green() != 0.0");
	test.assertEquals(negativeHTMLRed.blue(), 0.0, "negativeHTMLRed.blue() != 0.0");
	test.assertEquals(negativeHTMLRed.HTMLRed(), 255, "negativeHTMLRed.HTMLRed() != 255");
	test.assertEquals(negativeHTMLRed.HTMLGreen(), 0, "negativeHTMLRed.HTMLGreen() != 0");
	test.assertEquals(negativeHTMLRed.HTMLBlue(), 0, "negativeHTMLRed.HTMLBlue() != 0");
	test.assertEquals(negativeHTMLGreen.red(), .0, "negativeHTMLGreen.red() != 0.0");
	test.assertEquals(negativeHTMLGreen.green(), 1.0, "negativeHTMLGreen.green() != 1.0");
	test.assertEquals(negativeHTMLGreen.blue(), 0.0, "negativeHTMLGreen.blue() != 0.0");
	test.assertEquals(negativeHTMLGreen.HTMLRed(), 0, "negativeHTMLGreen.HTMLRed() != 0");
	test.assertEquals(negativeHTMLGreen.HTMLGreen(), 255, "negativeHTMLGreen.HTMLGreen() != 255");
	test.assertEquals(negativeHTMLGreen.HTMLBlue(), 0, "negativeHTMLGreen.HTMLBlue() != 0");
	test.assertEquals(negativeHTMLBlue.red(), 0.0, "negativeHTMLBlue.red() != 0.0");
	test.assertEquals(negativeHTMLBlue.green(), 0.0, "negativeHTMLBlue.green() != 0.0");
	test.assertEquals(negativeHTMLBlue.blue(), 1.0, "negativeHTMLBlue.blue() != 1.0");
	test.assertEquals(negativeHTMLBlue.HTMLRed(), 0, "negativeHTMLBlue.HTMLRed() != 0");
	test.assertEquals(negativeHTMLBlue.HTMLGreen(), 0, "negativeHTMLBlue.HTMLGreen() != 0");
	test.assertEquals(negativeHTMLBlue.HTMLBlue(), 255, "negativeHTMLBlue.HTMLBlue() != 255");
	test.assertEquals(negativeRed.red(), 1.0, "negativeRed.red() != 1.0");
	test.assertEquals(negativeRed.green(), 0.0, "negativeRed.green() != 0.0");
	test.assertEquals(negativeRed.blue(), 0.0, "negativeRed.blue() != 0.0");
	test.assertEquals(negativeRed.HTMLRed(), 255, "negativeRed.HTMLRed() != 255");
	test.assertEquals(negativeRed.HTMLGreen(), 0, "negativeRed.HTMLGreen() != 0");
	test.assertEquals(negativeRed.HTMLBlue(), 0, "negativeRed.HTMLBlue() != 0");
	test.assertEquals(negativeGreen.red(), 0.0, "negativeGreen.red() != 0.0");
	test.assertEquals(negativeGreen.green(), 1.0, "negativeGreen.green() != 1.0");
	test.assertEquals(negativeGreen.blue(), 0.0, "negativeGreen.blue() != 0.0");
	test.assertEquals(negativeGreen.HTMLRed(), 0, "negativeGreen.HTMLRed() != 0");
	test.assertEquals(negativeGreen.HTMLGreen(), 255, "negativeGreen.HTMLGreen() != 255");
	test.assertEquals(negativeGreen.HTMLBlue(), 0, "negativeGreen.HTMLBlue() != 0");
	test.assertEquals(negativeBlue.red(), 0.0, "negativeBlue.red() != 0.0");
	test.assertEquals(negativeBlue.green(), 0.0, "negativeBlue.green() != 0.0");
	test.assertEquals(negativeBlue.blue(), 1.0, "negativeBlue.blue() != 1.0");
	test.assertEquals(negativeBlue.HTMLRed(), 0, "negativeBlue.HTMLRed() != 0");
	test.assertEquals(negativeBlue.HTMLGreen(), 0, "negativeBlue.HTMLGreen() != 0");
	test.assertEquals(negativeBlue.HTMLBlue(), 255, "negativeBlue.HTMLBlue() != 255");
	test.assertEquals(maxHTMLRedBlue.red(), 1.0, "maxHTMLRedBlue.red() != 1.0");
	test.assertEquals(maxHTMLRedBlue.green(), 0.0, "maxHTMLRedBlue.green() != 0.0");
	test.assertEquals(maxHTMLRedBlue.blue(), 1.0, "maxHTMLRedBlue.blue() != 1.0");
	test.assertEquals(maxHTMLRedBlue.HTMLRed(), 255, "maxHTMLRedBlue.HTMLRed() != 255");
	test.assertEquals(maxHTMLRedBlue.HTMLGreen(), 0, "maxHTMLRedBlue.HTMLGreen() != 0");
	test.assertEquals(maxHTMLRedBlue.HTMLBlue(), 255, "maxHTMLRedBlue.HTMLBlue() != 255");
	test.assertEquals(maxHTMLRedGreen.red(), 1.0, "maxHTMLRedGreen.red() != 1.0");
	test.assertEquals(maxHTMLRedGreen.green(), 1.0, "maxHTMLRedGreen.green() != 1.0");
	test.assertEquals(maxHTMLRedGreen.blue(), 0.0, "maxHTMLRedGreen.blue() != 0.0");
	test.assertEquals(maxHTMLRedGreen.HTMLRed(), 255, "maxHTMLRedGreen.HTMLRed() != 255");
	test.assertEquals(maxHTMLRedGreen.HTMLGreen(), 255, "maxHTMLRedGreen.HTMLGreen() != 255");
	test.assertEquals(maxHTMLRedGreen.HTMLBlue(), 0, "maxHTMLRedGreen.HTMLBlue() != 0");
	test.assertEquals(maxHTMLGreenBlue.red(), 0.0, "maxHTMLGreenBlue.red() != 0.0");
	test.assertEquals(maxHTMLGreenBlue.green(), 1.0, "maxHTMLGreenBlue.green() != 1.0");
	test.assertEquals(maxHTMLGreenBlue.blue(), 1.0, "maxHTMLGreenBlue.blue() != 1.0");
	test.assertEquals(maxHTMLGreenBlue.HTMLRed(), 0, "maxHTMLGreenBlue.HTMLRed() != 0");
	test.assertEquals(maxHTMLGreenBlue.HTMLGreen(), 255, "maxHTMLGreenBlue.HTMLGreen() != 255");
	test.assertEquals(maxHTMLGreenBlue.HTMLBlue(), 255, "maxHTMLGreenBlue.HTMLBlue() != 255");
	test.assertEquals(maxGreenBlue.red(), 0.0, "maxGreenBlue.red() != 0.0");
	test.assertEquals(maxGreenBlue.green(), 1.0, "maxGreenBlue.green() != 1.0");
	test.assertEquals(maxGreenBlue.blue(), 1.0, "maxGreenBlue.blue() != 1.0");
	test.assertEquals(maxGreenBlue.HTMLRed(), 0, "maxGreenBlue.HTMLRed() != 0");
	test.assertEquals(maxGreenBlue.HTMLGreen(), 255, "maxGreenBlue.HTMLGreen() != 255");
	test.assertEquals(maxGreenBlue.HTMLBlue(), 255, "maxGreenBlue.HTMLBlue() != 255");
	test.assertEquals(maxRedBlue.red(), 1.0, "maxRedBlue.red() != 1.0");
	test.assertEquals(maxRedBlue.green(), 0.0, "maxRedBlue.green() != 0.0");
	test.assertEquals(maxRedBlue.blue(), 1.0, "maxRedBlue.blue() != 1.0");
	test.assertEquals(maxRedBlue.HTMLRed(), 255, "maxRedBlue.HTMLRed() != 255");
	test.assertEquals(maxRedBlue.HTMLGreen(), 0, "maxRedBlue.HTMLGreen() != 0");
	test.assertEquals(maxRedBlue.HTMLBlue(), 255, "maxRedBlue.HTMLBlue() != 255");
	test.assertEquals(maxRedGreen.red(), 1.0, "maxRedGreen.red() != 1.0");
	test.assertEquals(maxRedGreen.green(), 1.0, "maxRedGreen.green() != 1.0");
	test.assertEquals(maxRedGreen.blue(), 0.0, "maxRedGreen.blue() != 0.0");
	test.assertEquals(maxRedGreen.HTMLRed(), 255, "maxRedGreen.HTMLRed() != 255");
	test.assertEquals(maxRedGreen.HTMLGreen(), 255, "maxRedGreen.HTMLGreen() != 255");
	test.assertEquals(maxRedGreen.HTMLBlue(), 0, "maxRedGreen.HTMLBlue() != 0");
	test.assertEquals(black.red(), 0.0, "black.red() != 0.0");
	test.assertEquals(black.green(), 0.0, "black.green() != 0.0");
	test.assertEquals(black.blue(), 0.0, "black.blue() != 0.0");
	test.assertEquals(black.HTMLRed(), 0, "black.HTMLRed() != 0");
	test.assertEquals(black.HTMLGreen(), 0, "black.HTMLGreen() != 0");
	test.assertEquals(black.HTMLBlue(), 0, "black.HTMLBlue() != 0");
	test.assertEquals(white.red(), 1.0, "white.red() != 1.0");
	test.assertEquals(white.green(), 1.0, "white.green() != 1.0");
	test.assertEquals(white.blue(), 1.0, "white.blue() != 1.0");
	test.assertEquals(white.HTMLRed(), 255, "white.HTMLRed() != 255");
	test.assertEquals(white.HTMLGreen(), 255, "white.HTMLGreen() != 255");
	test.assertEquals(white.HTMLBlue(), 255, "white.HTMLBlue() != 255");
	test.assertEquals(whiteHTML.red(), 1.0, "whiteHTML.red() != 1.0");
	test.assertEquals(whiteHTML.green(), 1.0, "whiteHTML.green() != 1.0");
	test.assertEquals(whiteHTML.blue(), 1.0, "whiteHTML.blue() != 1.0");
	test.assertEquals(whiteHTML.HTMLRed(), 255, "whiteHTML.HTMLRed() != 255");
	test.assertEquals(whiteHTML.HTMLGreen(), 255, "whiteHTML.HTMLGreen() != 255");
	test.assertEquals(whiteHTML.HTMLBlue(), 255, "whiteHTML.HTMLBlue() != 255");
	test.assertEquals(blackHTML.red(), 0.0, "blackHTML.red() != 0.0");
	test.assertEquals(blackHTML.green(), 0.0, "blackHTML.green() != 0.0");
	test.assertEquals(blackHTML.blue(), 0.0, "blackHTML.blue() != 0.0");
	test.assertEquals(blackHTML.HTMLRed(), 0, "blackHTML.HTMLRed() != 0");
	test.assertEquals(blackHTML.HTMLGreen(), 0, "blackHTML.HTMLGreen() != 0");
	test.assertEquals(blackHTML.HTMLBlue(), 0, "blackHTML.HTMLBlue() != 0");
	test.assertEquals(maxHTMLRed.red(), 1, "maxHTMLRed.red() != 1");
	test.assertEquals(maxHTMLRed.green(), 0, "maxHTMLRed.green() != 0");
	test.assertEquals(maxHTMLRed.blue(), 0, "maxHTMLRed.blue() != 0");
	test.assertEquals(maxHTMLRed.HTMLRed(), 255, "maxHTMLRed.HTMLRed() != 255");
	test.assertEquals(maxHTMLRed.HTMLGreen(), 0, "maxHTMLRed.HTMLGreen() != 0");
	test.assertEquals(maxHTMLRed.HTMLBlue(), 0, "maxHTMLRed.HTMLBlue() != 0");
	test.assertEquals(maxHTMLBlue.red(), 0, "maxHTMLBlue.red() != 0");
	test.assertEquals(maxHTMLBlue.green(), 0, "maxHTMLBlue.green() != 0");
	test.assertEquals(maxHTMLBlue.blue(), 1, "maxHTMLBlue.blue() != 1");
	test.assertEquals(maxHTMLBlue.HTMLRed(), 0, "maxHTMLBlue.HTMLRed() != 0");
	test.assertEquals(maxHTMLBlue.HTMLGreen(), 0, "maxHTMLBlue.HTMLGreen() != 0");
	test.assertEquals(maxHTMLBlue.HTMLBlue(), 255, "maxHTMLBlue.HTMLBlue() != 255");
	test.assertEquals(maxHTMLGreen.red(), 0.0, "maxHTMLGreen.red() != 0.0");
	test.assertEquals(maxHTMLGreen.green(), 1.0, "maxHTMLGreen.green() != 1.0");
	test.assertEquals(maxHTMLGreen.blue(), 0.0, "maxHTMLGreen.blue() != 0.0");
	test.assertEquals(maxHTMLGreen.HTMLRed(), 0, "maxHTMLGreen.HTMLRed() != 0");
	test.assertEquals(maxHTMLGreen.HTMLGreen(), 255, "maxHTMLGreen.HTMLGreen() != 255");
	test.assertEquals(maxHTMLGreen.HTMLBlue(), 0, "maxHTMLGreen.HTMLBlue() != 0");
	test.assertEquals(maxRed.red(), 1.0, "maxRed.red() != 1.0");
	test.assertEquals(maxRed.green(), 0.0, "maxRed.green() != 0.0");
	test.assertEquals(maxRed.blue(), 0.0, "maxRed.blue() != 0.0");
	test.assertEquals(maxRed.HTMLRed(), 255, "maxRed.HTMLRed() != 255");
	test.assertEquals(maxRed.HTMLGreen(), 0, "maxRed.HTMLGreen() != 0");
	test.assertEquals(maxRed.HTMLBlue(), 0, "maxRed.HTMLBlue() != 0");
	test.assertEquals(maxGreen.red(), 0, "maxGreen.red() != 0");
	test.assertEquals(maxGreen.green(), 1.0, "maxGreen.green() != 1.0");
	test.assertEquals(maxGreen.blue(), 0, "maxGreen.blue() != 0");
	test.assertEquals(maxGreen.HTMLRed(), 0, "maxGreen.HTMLRed() != 0");
	test.assertEquals(maxGreen.HTMLGreen(), 255, "maxGreen.HTMLGreen() != 255");
	test.assertEquals(maxGreen.HTMLBlue(), 0, "maxGreen.HTMLBlue() != 0");
	test.assertEquals(maxBlue.red(), 0.0, "maxBlue.red() != 0.0");
	test.assertEquals(maxBlue.green(), 0.0, "maxBlue.green() != 0.0");
	test.assertEquals(maxBlue.blue(), 1.0, "maxBlue.blue() != 1.0");
	test.assertEquals(maxBlue.HTMLRed(), 0, "maxBlue.HTMLRed() != 0");
	test.assertEquals(maxBlue.HTMLGreen(), 0, "maxBlue.HTMLGreen() != 0");
	test.assertEquals(maxBlue.HTMLBlue(), 255, "maxBlue.HTMLBlue() != 255");
	test.assertEquals(maxHTMLGreen.red(), 0.0, "maxHTMLGreen.red() != 0.0");
	test.assertEquals(maxHTMLGreen.green(), 1.0, "maxHTMLGreen.green() != 1.0");
	test.assertEquals(maxHTMLGreen.blue(), 0.0, "maxHTMLGreen.blue() != 0.0");
	test.assertEquals(maxHTMLGreen.HTMLRed(), 0, "maxHTMLGreen.HTMLRed() != 0");
	test.assertEquals(maxHTMLGreen.HTMLGreen(), 255, "maxHTMLGreen.HTMLGreen() != 255");
	test.assertEquals(maxHTMLGreen.HTMLBlue(), 0, "maxHTMLGreen.HTMLBlue() != 0");
	test.assertEquals(maxHTMLBlue.red(), 0.0, "maxHTMLBlue.red() != 0.0");
	test.assertEquals(maxHTMLBlue.green(), 0.0, "maxHTMLBlue.green() != 0.0");
	test.assertEquals(maxHTMLBlue.blue(), 1.0, "maxHTMLBlue.blue() != 1.0");
	test.assertEquals(maxHTMLBlue.HTMLRed(), 0, "maxHTMLBlue.HTMLRed() != 0");
	test.assertEquals(maxHTMLBlue.HTMLGreen(), 0, "maxHTMLBlue.HTMLGreen() != 0");
	test.assertEquals(maxHTMLBlue.HTMLBlue(), 255, "maxHTMLBlue.HTMLBlue() != 255");
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



//  TODO:
//
//
//
//
