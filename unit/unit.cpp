#include "unit.hpp"
#include "rgbcolor/testrgbcolor.hpp"
#include "coordinate/testcoordinate.hpp"

int main(int argc, char *argv[])
{
	cout << "===\tStarting Tests\t===" << endl;

	//	Note that this file will only track unit tests which have failed and not those which passed
	//	Also note that the last column in the csv file is the condiitional statement. Probably there is a better way of doing this.
	string fname = "results.csv";
	ofstream output(fname.c_str(), ios::app);
	output << "time, test number, expected" << endl;

	output << "#===\tTesting rgbColor\t===" << endl;

	output << "#Testing constructors" << endl;
	if(!rgb_constructors(fname))
	{
		output << "#Error checking rgb constructors";
	}

	output << "#Testing toString" << endl;
	if(!rgb_toString(fname))
	{
		output << "#Error checking rgb toString" << endl;
	}

	output << "#Testing Mutators" << endl;
	if(!rgb_mutators(fname))
	{
		output << "#Error checking rgb mutators" << endl;
	}

	output << "#===\tTesting Coordinate\t===" << endl;

	output << "#Testing constructors" << endl;
	if(!coordinate_constructors(fname))
	{
		output << "#Error checking coordinate constructors" << endl;
	}

	output << "#Testing toString" << endl;
	if(!coordinate_toString(fname))
	{
		output << "#Error checking coordinate toString" << endl;
	}

	

	output.close();
	cout << "===\tEnding Tests\t===" << endl;

	return 0;
}



//	TODO:
//	Test coordinate
//
//
