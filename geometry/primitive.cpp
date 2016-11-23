#include "primitive.hpp"

#include <iostream>
using namespace std;

Primitive::Primitive()
{
	position.setX(1.0);
	position.setY(1.0);
}

Primitive::Primitive(Coordinate &position)
{

}

Primitive::Primitive(rgbColor *colors)
{

}

Primitive::Primitive(Coordinate &position, rgbColor *colors)
{

}

void Primitive::setPosition(Coordinate &position)
{
	position = position;
}

void Primitive::setColor(rgbColor *colors)
{

}

Coordinate Primitive::getPosition()
{
	return position;
}

rgbColor *Primitive::getColor()
{
	return colors;
}

// TODO:
//
//
//
