#ifndef SQUARE_HPP
#define SQUARE_HPP

#pragma once

#include "primitive.hpp"

class Square: public Primitive
{
private:
	rgbColor color[4];

public:

	Square();
	Square(double defaultLength, Coordinate defaultPosition);
	Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor);
	Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColors[]);

	rgbColor *getColor();
	Coordinate getURight();
	Coordinate getLRight();
	Coordinate getLLeft();
	Coordinate getULeft();

	void setColor(rgbColor newColor);
	void setColor(rgbColor newColors[]);

	void resize(double length);
	double volume();
	bool inRegion(Coordinate point);

	void draw();
};

#endif	//	SQUARE_HPP



//	TODO:
//	Draw and coordinates have an issue with the scaling factor for windows that
//	do not have symmetric dimensions.
//
//
