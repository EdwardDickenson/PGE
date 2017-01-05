#include "rgbcolor.hpp"

// The value, 0000 0000 0000 0000 0000 0000 1111 1111, is 255 in decimal
// The value, 0000 0000 0000 0000 1111 1111 0000 0000, is 65,280 in decimal
// The value, 0000 0000 1111 1111 0000 0000 0000 0000, is 16,711,680 in decimal

// The value, 65,535, is 0000 0000 1111 1111 1111 1111 in binary
// The value, 16,711,935, is 0000 0000 1111 1111 0000 0000 1111 1111 in binary
// The value, 16,776,960, is 0000 0000 1111 1111 1111 1111 0000 0000 in binary
// The value, 16,777,215, is 0000 0000 1111 1111 1111 1111 1111 1111 in binary

rgbColor::rgbColor()
{
	htmlColor = 16777215;
}

rgbColor::rgbColor(double red, double green, double blue)
{
	htmlColor = 0;

	if(	red < 0.0 || green < 0.0 || blue < 0.0 ||
		red > 1.0 || green > 1.0 || blue > 1.0)
	{
		htmlColor = 16777215;
		return;
	}

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
	if(	red < 0 || green < 0 || blue < 0 ||
		red > 255 || green > 255 || blue > 255)
	{
		htmlColor = 16777215;
		return;
	}

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

rgbColor::rgbColor(string fromString)
{

}

double rgbColor::red()
{
	return double((htmlColor & 16711680) >> 16) / 255.0;
}

double rgbColor::green()
{
	return double((htmlColor & 65280) >> 8) / 255.0;
}

double rgbColor::blue()
{
	return double((htmlColor & 255)) / 255.0;
}

int rgbColor::HTMLRed()
{
	return ((htmlColor >> 16) & 255);
}

int rgbColor::HTMLGreen()
{
	return ((htmlColor >> 8) & 255);
}

int rgbColor::HTMLBlue()
{
	return (htmlColor & 255);
}

int rgbColor::HTML()
{
	return htmlColor;
}

void rgbColor::setRed(double red)
{
	int htmlRed = int(red * 255);
	htmlRed = htmlRed << 16;
	htmlColor = htmlColor & (65535 | htmlRed);
}

void rgbColor::setGreen(double green)
{
	int htmlGreen = int(green * 255);
	htmlGreen = htmlGreen << 8;
	htmlColor = htmlColor & (16711935 | htmlGreen);
}

void rgbColor::setBlue(double blue)
{
	int htmlBlue = int(blue * 255);
	htmlColor = htmlColor & (16776960 | htmlBlue);
}

void rgbColor::setColor(double red, double green, double blue)
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

void rgbColor::setHTMLRed(int red)
{
	red = red << 16;
	htmlColor = htmlColor & 65535;
	htmlColor = htmlColor | red;
}

void rgbColor::setHTMLGreen(int green)
{
	green = green << 8;
	htmlColor = htmlColor & 16711935;
	htmlColor = htmlColor | green;
}

void rgbColor::setHTMLBlue(int blue)
{
	htmlColor = htmlColor & 16776960;
	htmlColor = htmlColor | blue;
}

void rgbColor::setColor(int red, int green, int blue)
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

string rgbColor::toString()
{
	stringstream  result;

	int red = htmlColor & 16711680;
	red = red >> 16;
	int green = htmlColor & 65280;
	green = green >> 8;
	int blue = htmlColor & 255;

	result << "#";

	if(red < 10)
	{
		result << 0;
	}

	result << hex << red;

	if(green < 10)
	{
		result << 0;
	}

	result << hex << green;

	if(blue < 10)
	{
		result << 0;
	}

	result << hex << blue;

	return result.str();
}



// TODO:
//	Change the name of the functions from get<color> to simply <color>
//
//
//
