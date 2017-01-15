#include "square.hpp"

Square::Square()
{
	length = 0;
	position.setXY(0.0, 0.0);

	rgbColor tmp(255, 255, 255);
	color = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition)
{
	length = defaultLength;
	position = defaultPosition;

	rgbColor tmp(255, 255, 255);
	color = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor)
{
	length = defaultLength;
	position = defaultPosition;

	color = defaultColor;
}

void Square::resize(double newLength)
{
	setLength(newLength);
	position.set(newLength / 2);
}

rgbColor Square::getColor()
{
	return color;
}

Coordinate Square::getURight()
{
	return position;
}

Coordinate Square::getLRight()
{
	Coordinate result(position.getRelX(), position.getRelY() - length);
	return result;
}

Coordinate Square::getLLeft()
{
	Coordinate result(position.getRelX() - length, position.getRelY() - length);
	return result;
}

Coordinate Square::getULeft()
{
	Coordinate result(position.getRelX() - length, position.getRelY());
	return result;
}

double Square::volume()
{
	return length * length;
}

bool Square::inRegion(Coordinate point)
{
	double w = point.getRelX();
	double x = point.getRelY();
	double y = position.getRelX();
	double z = position.getRelY();

	if(	w <= y && w >= (w - length) && // Check if the point's x value is inside of the square
		x <= z && x >= (z - length))
	{
		return true;
	}

	return false;
}



//	TODO:
//
//
//
