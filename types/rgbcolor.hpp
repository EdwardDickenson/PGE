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
	rgbColor(int defaultHTMLColor);
	rgbColor(int htmlR, int htmlG, int htmlB);
	rgbColor(double defaulR, double defaultG, double defaultB);

	int getHTML();
	int getHTMLR();
	int getHTMLG();
	int getHTMLB();
	double getR();
	double getG();
	double getB();

	void setR(double newR);
	void setG(double newG);
	void setB(double newB);
	void setHTML(int newHTMLColor);
	void setHTMLR(int newHTMLR);
	void setHTMLG(int newHTMLG);
	void setHTMLB(int newHTMLB);

	string html();
};

#endif	//	RGB_COLOR_HPP


//	TODO:
//
//
//
