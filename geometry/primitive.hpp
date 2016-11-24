#ifndef Primitive_HPP
#define Primitive_HPP

#pragma once

#include "../deps.hpp"
#include "../types/types.hpp"

class Primitive
{
protected:

	Coordinate position;
	//rgbColor *color;	// Using a simple array because the number of vertices in
						// a polygon is fixed even if this class does not know
						// how many vertices its children will have.

	double length;	// The name "length" might not appropriate for all
					// geometries but its meaning should still be clear.

public:

	Primitive();
	Primitive(double defaultLength, Coordinate &position);
	//Primitive(double defaultLength, rgbColor *defaultColor);
	//Primitive(Coordinate &position, rgbColor *defaultColor);

	void setPosition(Coordinate &newPosition);
	//void setColor(rgbColor *newColor);
	void setLength(double newLength);

	double getLength();
	Coordinate getPosition();
	//rgbColor *getColor();
};

#endif // Primitive_HPP



//
//
//
//
