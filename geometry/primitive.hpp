#ifndef Primitive_HPP
#define Primitive_HPP

#pragma once

#include "../deps.hpp"
#include "../types/types.hpp"

class Primitive
{
protected:

	Coordinate position;
	rgbColor *colors;	// Using a simple array because the number of vertices in
						// a polygon is fixed even if this class does not know
						// how many vertices its children will have

public:

	Primitive();
	Primitive(Coordinate &position);
	Primitive(rgbColor *colors);
	Primitive(Coordinate &position, rgbColor *color);

	void setPosition(Coordinate &position);
	void setColor(rgbColor *colors);

	Coordinate getPosition();
	rgbColor *getColor();

	double volume();
};

#endif // Primitive_HPP



//
//
//
//
