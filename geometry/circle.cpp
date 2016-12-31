#include "circle.hpp"

Circle::Circle()
{
	radius = 0;

	position.setX(0);
	position.setY(0);

	rgbColor tmp(1.0, 1.0, 1.0);
	/*color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;*/
}

Circle::Circle(double defaultRadius, Coordinate defaultPosition)
{
	radius = defaultRadius;
	position.setX(defaultPosition.getX());
	position.setY(defaultPosition.getY());

	rgbColor tmp(1.0, 1.0, 1.0);
	/*color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;*/
}

Circle::Circle(double defaultRadius, Coordinate defaultPosition, rgbColor defaultColor)
{
	radius = defaultRadius;
	position.setX(defaultPosition.getX());
	position.setY(defaultPosition.getY());
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
	double w = point.getX();
	double x = point.getY();
	double y = position.getX();
	double z = position.getY();

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
