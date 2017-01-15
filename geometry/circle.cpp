#include "circle.hpp"

Circle::Circle()
{
	radius = 0;

	position.setX(0.0);
	position.setY(0.0);

	rgbColor tmp(1.0, 1.0, 1.0);
}

Circle::Circle(double defaultRadius, Coordinate defaultPosition)
{
	radius = defaultRadius;
	position.setX(defaultPosition.getRelX());
	position.setY(defaultPosition.getRelY());

	rgbColor tmp(1.0, 1.0, 1.0);
}

Circle::Circle(double defaultRadius, Coordinate defaultPosition, rgbColor defaultColor)
{
	radius = defaultRadius;
	position.setX(defaultPosition.getRelX());
	position.setY(defaultPosition.getRelY());
}

double Circle::getRadius()
{
	return radius;
}

Coordinate Circle::getPosition()
{
	return position;
}

rgbColor Circle::getColor()
{
	return color;
}

void Circle::setRadius(double newRadius)
{
	radius = newRadius;
}

void Circle::setPosition(Coordinate newPosition)
{
	position = newPosition;
}

void Circle::setColor(rgbColor newColor)
{
	color = newColor;
}

void Circle::resize(double newRadius)
{

}

double Circle::volume()
{
	return (3.141592654) * (radius * radius);
}

bool Circle::inRegion(Coordinate point)
{
	double w = point.getRelX();
	double x = point.getRelY();
	double y = position.getRelX();
	double z = position.getRelY();

	if(	w <= y && w >= (w - length) &&
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
