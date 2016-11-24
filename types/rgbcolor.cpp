#include "rgbcolor.hpp"

rgbColor::rgbColor()
{
	htmlColor = 0;
}

rgbColor::rgbColor(double defaultR, double defaultG, double defaultB)
{
	htmlColor = 0;

	int red = int(defaultR * 255); // Instead of multiplying, I could use bitshifting, booth's algorithm, to multiply but let's profile this first
	int green = int(defaultG * 255);
	int blue = int(defaultB * 255);

	htmlColor += red;
	htmlColor = htmlColor << 8;

	htmlColor += green;
	htmlColor = htmlColor << 8;

	htmlColor += blue;
	// This is where the shift, by the same amount as the others, for the blue
	// value would go. If we implement alpha vlaues then we will have to include
	// that, but for now leaving it as it is, is also fine.
}

double rgbColor::getR()
{
	return double(((htmlColor & 16711680) >> 16) / 255); // Divide by 255 might be possible with bitshifting
}

double rgbColor::getG()
{
	return double(((htmlColor & 65280) >> 8) / 255); // Divide by 255 might be possible with bitshifting
}

double rgbColor::getB()
{
	return double(((htmlColor & 255)) / 255); // Divide by 255 might be possible with bitshifting
}

void rgbColor::setR(double newR)
{
	int red = int(newR * 255);
	red = red << 16;
	htmlColor = htmlColor & (65535 | red);
}

void rgbColor::setG(double newG)
{
	int green = int(newG * 255);
	green = green << 8;
	htmlColor = htmlColor & (16711935 | green);
}

void rgbColor::setB(double newB)
{
	int blue = int(newB * 255);
	htmlColor = htmlColor & (16776960 | blue);
}

string rgbColor::html()
{
	stringstream  result;

	int mask = 255;
	int blue = htmlColor & mask;
	mask = mask << 8;
	int green = htmlColor & mask;
	mask = mask << 8;
	int red = htmlColor & mask;
	red = red >> 16;
	green = green >> 8;

	result << "#" << hex << red << green << blue;

	return result.str();
}



// TODO:
//
//
//
//
