#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#pragma once

#include "primitive.hpp"

class Circle : public Primitive
{
private:

	double radius;
	Coordinate position;
	rgbColor color;

public:

	Circle();
	Circle(double defaultRadius, Coordinate defaultPosition);
	Circle(double defaultRadius, Coordinate defaultPosition, rgbColor defaultColor);

	double getRadius();
	Coordinate getPosition();
	rgbColor getColor();
	void setRadius(double newRadius);
	void setPosition(Coordinate newPosition);
	void setColor(rgbColor newColor);

	void resize(double newRadius);
	double volume();
	bool inRegion(Coordinate point);
};

#endif // CIRCLE_HPP



//	TODO:
//
//
//
