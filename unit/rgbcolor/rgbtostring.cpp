#include "testrgbcolor.hpp"

bool test_rgb_toString(string fname)
{
	ofstream output(fname.c_str(), ios::app);
	bool result = true;
	clock_t curr_time;

	rgbColor color;
	rgbColor black(0, 0, 0);
	rgbColor half(127, 127, 127);
	rgbColor zeroHalfOne(0, 127, 255);
	rgbColor OneHalfZero(255, 127, 0);

	++ntests;
	if(color.toString() !="#ffffff")
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.toString() !=\"#ffffff\"" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(black.toString() != "#000000")
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.toString() != \"#000000\"" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(half.toString() != "#7f7f7f")
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "half.toString() != \"#7f7f7f\"" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(zeroHalfOne.toString() != "#007fff")
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "zeroHalfOne.toString() != \"#007fff\"" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(OneHalfZero.toString() != "#ff7f00")
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "OneHalfZero.toString() != \"#007fff\"" << endl;
		++nfailed;
		result = false;
	}

	return result;
}
