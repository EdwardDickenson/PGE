#include "testrgbcolor.hpp"

bool test_rgb_constructors(string fname)
{
	ofstream output(fname.c_str(), ios::app);
	bool result = true;
	clock_t curr_time;

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
	rgbColor tooBigGreen(2.0, 2.0, 0.0);
	rgbColor tooBigBlue(2.0, 0.0, 2.0);
	rgbColor tooBigHTMLRed(1024, 0, 0);
	rgbColor tooBigHTMLGreen(0, 1024, 0);
	rgbColor tooBigHTMLBlue(0, 0, 1024);
	rgbColor half(127, 127, 127);	//	Not going to go crazy on this one
	rgbColor fromMask(half.HTML());
	rgbColor fromString(half.toString());

	++ntests;
	for(int i = 0; i < 255; ++i)
	{
		for(int j = 0; j < 255; ++j)
		{
			for(int k = 0; k < 255; ++k)
			{
				rgbColor generated(i, j, k);

				if(generated.red() != (double(i) / 255))
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.red() != " << i << endl;
					++nfailed;
					result = false;
				}

				if(generated.green() != (double(j) / 255))
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.green() != " << j << endl;
					++nfailed;
					result = false;
				}

				if(generated.blue() != (double(k) / 255))
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.blue() != " << k << endl;
					++nfailed;
					result = false;
				}

				if(generated.HTMLRed() != i)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLRed() != " << i << endl;
					++nfailed;
					result = false;
				}

				if(generated.HTMLGreen() != j)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLGreen() != " << j << endl;
					++nfailed;
					result = false;
				}

				if(generated.HTMLBlue() != k)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLBlue() != " << k << endl;
					++nfailed;
					result = false;
				}
			}
		}
	}

	++ntests;
	if(fromMask.red() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.red() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(fromMask.green() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.green() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(fromMask.blue() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.blue() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(fromMask.HTMLRed() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.HTMLRed() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(fromMask.HTMLGreen() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.HTMLGreen() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(fromMask.HTMLBlue() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "fromMask.HTMLBlue() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.red() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.red() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.green() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.green() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.blue() != (double(127) / 255))
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.blue() != (double(127) / 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.HTMLRed() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.HTMLRed() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.HTMLGreen() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.HTMLGreen() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.HTMLBlue() != 127)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.HTMLBlue() != 127" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLRed.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLRed.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLGreen.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLGreen.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigHTMLBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigHTMLBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigRed.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigRed.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigGreen.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigGreen.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(tooBigBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "tooBigBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLRed.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLRed.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLGreen.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLGreen.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeHTMLBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeHTMLBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeRed.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeRed.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeGreen.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeGreen.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(negativeBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "negativeBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRedGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRedGreen.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreenBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreenBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreenBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreenBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRedGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRedGreen.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(white.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "white.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(whiteHTML.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "whiteHTML.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(blackHTML.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "blackHTML.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.green() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.green() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.blue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.blue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLRed.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLRed.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLRed() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxRed.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxRed.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.red() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.red() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.blue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.blue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxGreen.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.blue != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.blue() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.blue() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLGreen.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLGreen.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.red() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.red() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.green() != 0.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.green() != 0.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(maxHTMLBlue.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "maxHTMLBlue.HTMLBlue() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.red() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.red() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.green() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.green() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.blue() != 1.0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.blue() != 1.0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLRed() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLRed() != 255)" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLGreen() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLGreen() != 255" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLBlue() != 255)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLBlue() != 255" << endl;
		++nfailed;
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
