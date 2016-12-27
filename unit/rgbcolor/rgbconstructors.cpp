#include "testrgbcolor.hpp"

bool test_rgb_constructors(string fname)
{
	unsigned long long ntests = 0;
	ofstream output(fname.c_str(), ios::app);
	clock_t curr_time;
	bool result = true;

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
	rgbColor negative(-1.0, 0.0, 0.0);
	rgbColor negativeHTML(-255, 0, 0);
	rgbColor tooBig(2.0, 0.0, 0.0);
	rgbColor tooBigHTML(1024, 0, 0);

	++ntests;
	if(tooBigHTML.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBigHTML.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBigHTML.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBigHTML.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(tooBigHTML.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(tooBigHTML.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTML.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(tooBig.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBig.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negativeHTML.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTML.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negative.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(negative.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negative.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(negative.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negative.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(black.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(black.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(white.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(white.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(white.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(white.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(white.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(white.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.green() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.green() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.blue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.blue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLRed() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.red() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.red() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.blue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.blue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.blue != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLBlue() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.red() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.green() != 0.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLRed() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLGreen() != 0" << endl;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLBlue() != 255" << endl;
		result = false;
	}

	++ntests;
	if(color.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.red() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.green() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.blue() != 1.0" << endl;
		result = false;
	}

	++ntests;
	if(color.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLRed() != 255)" << endl;
		result = false;
	}

	++ntests;
	if(color.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLGreen() != 255" << endl;
		result = false;
	}

	++ntests;
	if(color.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLBlue() != 255" << endl;
		result = false;
	}

	output.close();

	return result;
}



//  TODO:
//
//
//
//
