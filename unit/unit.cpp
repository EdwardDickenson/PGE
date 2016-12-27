#include "unit.hpp"
#include "rgbcolor/testrgbcolor.hpp"

int main(int argc, char *argv[])
{
	cout << "===\tStarting Tests\t===" << endl;

	unsigned long long ntests = 0;

	//	Note that this file will only track unit tests which have failed and not those which passed
	//	Also note that the last column in the csv file is the condiitional statement. Probably there is a better way of doing this.
	string fname = "results.csv";
	ofstream output(fname.c_str(), ios::app);
	output << "time, test number, result" << endl;

	output << "#===\tTesting rgbColor\t===" << endl;
	output << "#Testing constructors" << endl;
	test_rgb_constructors(fname);
	output << "#Number of unit tests: " << ntests << endl;

	output.close();
	cout << "===\tEnding Tests\t===" << endl;

	return 0;
}
