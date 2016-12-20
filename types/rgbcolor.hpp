#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#pragma once

#include "../deps.hpp"

class rgbColor
{
private:
	unsigned int htmlColor;

public:

	rgbColor();
	rgbColor(double red, double green, double blue);
	rgbColor(int red, int green, int blue);
	rgbColor(unsigned int html);

	double getRed();
	double getGreen();
	double getBlue();
	int getHTML();
	int getHTMLRed();
	int getHTMLGreen();
	int getHTMLBlue();

	void setRed(double red);
	void setGreen(double green);
	void setBlue(double blue);
	void setColor(double red, double green, double blue);
	void setHTMLRed(int red);
	void setHTMLGreen(int green);
	void setHTMLBlue(int blue);
	void setColor(int red, int green, int blue);
	void setHTML(unsigned int html);

	string html();
};

#endif	//	RGB_COLOR_HPP


//	TODO:
//
//
//
