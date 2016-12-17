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
	rgbColor(double defaulR, double defaultG, double defaultB);
	rgbColor(int htmlR, int htmlG, int htmlB);
	rgbColor(int defaultHTMLColor);

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
	void setColor(double newR, double newG, double newB);
	void setHTMLR(int newHTMLR);
	void setHTMLG(int newHTMLG);
	void setHTMLB(int newHTMLB);
	void setColor(int newHTMLR, int newHTMLG, int newHTMLB);
	void setHTML(int newHTMLColor);

	string html();
};

#endif	//	RGB_COLOR_HPP


//	TODO:
//
//
//
