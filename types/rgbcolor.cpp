#include "rgbcolor.hpp"

// The value, 0000 0000 0000 0000 0000 0000 1111 1111, is 255 in decimal
// The value, 0000 0000 0000 0000 1111 1111 0000 0000, is 65,280 in decimal
// The value, 0000 0000 1111 1111 0000 0000 0000 0000, is 16,711,680 in decimal

// The value, 65,535, is 0000 0000 1111 1111 1111 1111 in binary
// The value, 16,711,935, is 1111 1111 0000 0000 1111 1111 in binary
// The value, 16,776,960, is 1111 1111 1111 1111 0000 0000 in binary

rgbColor::rgbColor()
{
	htmlColor = 0;
}

rgbColor::rgbColor(double red, double green, double blue)
{
	htmlColor = 0;

	int htmlRed = int(red * 255); // Instead of multiplying, I could use bitshifting, booth's algorithm, to multiply but let's profile this first
	int htmlGreen = int(green * 255);
	int htmlBlue = int(blue * 255);

	htmlColor += htmlRed;
	htmlColor = htmlColor << 8;

	htmlColor += htmlGreen;
	htmlColor = htmlColor << 8;

	htmlColor += htmlBlue;
	// This is where the shift, by the same amount as the others, for the blue
	// value would go. If we implement alpha vlaues then we will have to include
	// that, but for now leaving it as it is is also fine.
}

rgbColor::rgbColor(int red, int green, int blue)
{
	htmlColor = red;
	htmlColor = htmlColor << 8;
	htmlColor += green;
	htmlColor = htmlColor << 8;
	htmlColor += blue;
}

rgbColor::rgbColor(unsigned int html)
{
	htmlColor = html;
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

int rgbColor::getHTMLR()
{
	return ((htmlColor >> 16) & 255); // Write a unit test to see if the int will wrap around
}

int rgbColor::getHTMLG()
{
	return ((htmlColor >> 8) & 255); // Write a unit test to see if the int will wrap around
}

int rgbColor::getHTMLB()
{
	return (htmlColor & 255); // Write a unit test to see if the int will wrap around
}

int rgbColor::getHTML()
{
	return htmlColor;
}

void rgbColor::setR(double red)
{
	int htmlRed = int(red * 255);
	htmlRed = htmlRed << 16;
	htmlColor = htmlColor & (65535 | htmlRed);
}

void rgbColor::setG(double green)
{
	int htmlGreen = int(green * 255);
	htmlGreen = htmlGreen << 8;
	htmlColor = htmlColor & (16711935 | htmlGreen);
}

void rgbColor::setB(double blue)
{
	int htmlBlue = int(blue * 255);
	htmlColor = htmlColor & (16776960 | htmlBlue);
}

void rgbColor::setColor(double red, double green, double blue) // This implementation makes the code more brittle. However, since this will not be change again it will be OK.
{
	int htmlRed = int(red * 255);
	htmlRed = htmlRed << 16;
	htmlColor = htmlColor & (65535 | htmlRed);

	int htmlGreen = int(green * 255);
	htmlGreen = htmlGreen << 8;
	htmlColor = htmlColor & (16711935 | htmlGreen);

	int htmlBlue = int(blue * 255);
	htmlColor = htmlColor & (16776960 | htmlBlue);
}

void rgbColor::setHTMLR(int red)
{
	red = red << 16;
	htmlColor = htmlColor & 65535;
	htmlColor = htmlColor | red;
}

void rgbColor::setHTMLG(int green)
{
	green = green << 8;
	htmlColor = htmlColor & 16711935;
	htmlColor = htmlColor | green;
}

void rgbColor::setHTMLB(int blue)
{
	htmlColor = htmlColor & 16776960;
	htmlColor = htmlColor | blue;
}

void rgbColor::setColor(int red, int blue, int green)
{
	red = red << 16;
	htmlColor = htmlColor & 65535;
	htmlColor = htmlColor | red;

	green = green << 8;
	htmlColor = htmlColor & 16711935;
	htmlColor = htmlColor | green;

	htmlColor = htmlColor & 16776960;
	htmlColor = htmlColor | blue;
}

void rgbColor::setHTML(unsigned int html)
{
	htmlColor = html;
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
