#include "primitive.hpp"

#include <iostream>
using namespace std;

Primitive::Primitive()
{
	length = 0;
	position.setXY(0.0, 0.0);

	rgbColor tmp(1.0, 1.0, 1.0);
}

Primitive::Primitive(double defaultLength, Coordinate &defaultPosition)
{
	length = defaultLength;
	position = defaultPosition;
}

void Primitive::setPosition(Coordinate &newPosition)
{
	position = newPosition;
}


void Primitive::setLength(double newLength)
{
	length = newLength;
}

Coordinate Primitive::getPosition()
{
	return position;
}

double Primitive::getLength()
{
	return length;
}

// TODO:
//
//
//
