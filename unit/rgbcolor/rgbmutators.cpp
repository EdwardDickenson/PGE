#include "testrgbcolor.hpp"

bool test_rgb_mutators(string fname)
{
	ofstream output(fname.c_str(), ios::app);
	bool result = true;
	clock_t curr_time;

	rgbColor color;
	rgbColor generated;
	rgbColor black(0, 0, 0);

	++ntests;
	for(int i = 0; i < 255; ++i)
	{
		for(int j = 0; j < 255; ++j)
		{
			for(int k = 0; k < 255; ++k)
			{
				generated.setColor(i, j, k);

				if(generated.HTMLRed() != i)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLRed() != " << i << ", " << generated.HTMLRed() << endl;
					++nfailed;
					result = false;
				}

				if(generated.HTMLGreen() != j)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLGreen() != " << j << ", " << generated.HTMLGreen() << endl;
					++nfailed;
					result = false;
				}

				if(generated.HTMLBlue() != k)
				{
					curr_time = clock();
					output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "generated.HTMLBlue() != " << k << ", " << generated.HTMLBlue() <<  endl;
					++nfailed;
					result = false;
				}
			}
		}
	}

	color.setRed(0);

	++ntests;
	if(color.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLRed() != 0" << endl;
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

	color.setGreen(0);

	++ntests;
	if(color.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLGreen() != 0" << endl;
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

	color.setBlue(0);

	++ntests;
	if(color.HTMLRed() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLRed() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLGreen() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLGreen() != 0" << endl;
		++nfailed;
		result = false;
	}

	++ntests;
	if(color.HTMLBlue() != 0)
	{
		curr_time = clock();
		output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.HTMLBlue() != 0" << endl;
		++nfailed;
		result = false;
	}



	return result;
}
