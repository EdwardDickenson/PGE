#ifndef SQUARE_HPP
#define SQUARE_HPP

#pragma once

#include "primitive.hpp"

class Square: public Primitive
{
private:
	rgbColor color;

public:

	Square();
	Square(double defaultLength, Coordinate defaultPosition);
	Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor);

	rgbColor getColor();
	Coordinate getURight();
	Coordinate getLRight();
	Coordinate getLLeft();
	Coordinate getULeft();

	void setColor(rgbColor &newColor);
	void resize(double length);
	void rotate(int degrees);
	double volume();
	bool inRegion(Coordinate point);
};

#endif	//	SQUARE_HPP



//	TODO:
//	Draw and coordinates have an issue with the scaling factor for windows that
//	do not have symmetric dimensions.
//
//	Include an additional constructor and mutator which accepts as arguments the
//	coordinates of the four points. An acceptable variation of this would be to
//	include the diagonal from the UR point.
//
//
//
