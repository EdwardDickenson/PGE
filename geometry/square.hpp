#ifndef SQUARE_HPP
#define SQUARE_HPP

#pragma once
//#$(cc) main.o function_map.o draw.o rgbcolor.o coordinate.o square.o circle.o displacement.o -o main $(deps)
#include "primitive.hpp"

class Square:public Primitive
{
private:

	double length;
	Coordinate position;	//	Position is assumed to be the upper right corner
	rgbColor color[4];

public:

	Square();
	Square(double defaultLength, Coordinate defaultPosition);
	Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor);
	Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColors[], int argc);

	double getLength();
	//Coordinate getPosition();
	rgbColor *getColor();
	void setLength(double newLength);
	//void setPosition(Coordinate defaultPosition);
	void setColor(rgbColor newColor);
	void setColor(rgbColor newColors[], int argc);

	void resize(double lenth);
	//double volume();

	void draw();
};

#endif	//	SQUARE_HPP



//	TODO:
//
//	Draw and coordinates have an issue with the scaling factor for windows that
//	do not have symmetric dimensions.
//
//
