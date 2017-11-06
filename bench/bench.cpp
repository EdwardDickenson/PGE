#include "bench.hpp"
#include "coordinate/coord.hpp"

int main(int argc, char *argv[])
{
	cout << "===\tStarting Benchmarks\t===" << endl;

	string fname = "results.csv";
	ofstream output(fname.c_str(), ios::app);

	coordinate_constructors(fname);

	cout << "===\tEnding Benchmarks\t===" << endl;

	return 0;
}



//	TODO:
//
//
//
