#ifndef TESTRGB_HPP
#define TESTRGB_HPP

#include "units.hpp"

bool test_rgb_constructors(string fname)
{
  ofstream output(fname.c_str());
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
  rgbColor maxBlueGreen(0.0, 1.0, 1.0);
  rgbColor maxHTMLGreen(255, 0, 0);
  rgbColor maxHTMLBlue(255, 0, 0);
  rgbColor maxHTMLRedGreen(255, );
  rgbColor negative(-1.0, 0.0, 0.0);
  rgbColor negativeHTML(-255);
  rgbColor tooBig(2.0, 0, 0);
  rgbColor tooBigHTML(1024, 0, 0);

  if(black.getRed() != 0.0)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getRed() != 0.0" << endl;
    ++ntests;
    result = false;
  }

  if(black.getGreen() != 0.0)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getGreen() != 0.0" << endl;
    ++ntests;
    result = false;
  }

  if(black.getBlue() != 0.0)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "black.getBlue() != 0.0" << endl;
    ++ntests;
    result = false;
  }

  if(color.getRed() != 1.0)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << "color.getRed() != 1.0" << endl;
    ++ntests;
    result = false;
  }

  if(color.getGreen() != 1.0)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << color.getGreen() << endl;
    ++ntests;
    result = false;
  }

  // ...
  //getBlue
  // ...

  if(color.getBlue() != 1.0
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << color.getBlue() << endl;
    ++ntests;
    result = false;
  }

  if(color.getHTMLRed() != 255)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << color.getHTMLRed() << endl;
    ++ntests;
    result = false;
  }

  if(color.getHTMLGreen() != 255)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << color.getHTMLGreen() << endl;
    ++ntests;
    result = false;
  }

  if(color.getHTMLBlue() != 255)
  {
    curr_time = clock();
    output << (((double)curr_time) / CLOCKS_PER_SEC) << "," << ntests << "," << color.getBlue() << endl;
    ++ntests;
    result = false;
  }

  if(maxHTMLRed.getHTMLRed() != 255
  {

  }

  output.close();

  return result;
}

#endif // TESTRGB_HPP



//  TODO:
//
//
//
//
