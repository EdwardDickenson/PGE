#include "../deps.hpp"
#include "../geometry/geometry.hpp"
#include "../types/types.hpp"
#include "../draw.hpp"

#include "units.hpp"
#include "testrgb.hpp"

#include

int main(int argc, char *argv[])
{
  cout << "===\tStarting Tests\t===" << endl;

  // Note that this file will only track unit tests which have failed and not those which passed
  string fname = "results.csv";
  ofstream output(fname.c_str());

  if(!ofstream(fname.c_str()))
  {
    cout << "time, test number, result"
  }

  // "#" denotes a line to be ignored, cleaned?, by what ever program processes this data
  output << "#"

  test_rgb_constructors(fname);

  cout << "===\tEnding Tests\t\t===" << endl;

  return 0;
}
