#include "square.hpp"

Square::Square()
{
	length = 0;
	position.setXY(0, 0);

	rgbColor tmp(255, 255, 255);
	color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition)
{
	length = defaultLength;
	position = defaultPosition;

	rgbColor tmp(255, 255, 255);
	color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor)
{
	length = defaultLength;
	position = defaultPosition;

	color[0] = defaultColor;
	color[1] = defaultColor;
	color[2] = defaultColor;
	color[3] = defaultColor;
}

Square::Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColors[])
{
	length = defaultLength;
	position = defaultPosition;

	color[0] = defaultColors[0];
	color[1] = defaultColors[1];
	color[2] = defaultColors[2];
	color[3] = defaultColors[3];
}

void Square::resize(double newLength)
{
	setLength(newLength);
	position.set(newLength / 2);
}

rgbColor *Square::getColor()
{
	return color;
}

Coordinate Square::getURight()
{
	return position;
}

Coordinate Square::getLRight()
{
	Coordinate result(position.getX(), position.getY() - length);
	return result;
}

Coordinate Square::getLLeft()
{
	Coordinate result(position.getX() - length, position.getY() - length);
	return result;
}

Coordinate Square::getULeft()
{
	Coordinate result(position.getX() - length, position.getY());
	return result;
}

double Square::volume()
{
	return length * length;
}

bool Square::inRegion(Coordinate point)
{
	double w = point.getX();
	double x = point.getY();
	double y = position.getX();
	double z = position.getY();

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
