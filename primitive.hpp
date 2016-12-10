#ifndef Primitive_HPP
#define Primitive_HPP

#pragma once

#include "../deps.hpp"
#include "../types/types.hpp"

class Primitive
{
protected:

	Coordinate position;

	double length;	// The name "length" might not appropriate for all
					// geometries but its meaning should still be clear.

public:

	Primitive();
	Primitive(double defaultLength, Coordinate &position);

	void setPosition(Coordinate &newPosition);
	void setLength(double newLength);

	double getLength();
	Coordinate getPosition();
};

#endif // Primitive_HPP



//
//
//
//
