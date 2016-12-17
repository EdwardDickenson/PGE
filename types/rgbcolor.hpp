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

	double getR();
	double getG();
	double getB();
	int getHTML();
	int getHTMLR();
	int getHTMLG();
	int getHTMLB();

	void setR(double red);
	void setG(double green);
	void setB(double blue);
	void setColor(double red, double green, double blue);
	void setHTMLR(int red);
	void setHTMLG(int green);
	void setHTMLB(int blue);
	void setColor(int red, int green, int blue);
	void setHTML(unsigned int html);

	string html();
};

#endif	//	RGB_COLOR_HPP


//	TODO:
//
//
//
