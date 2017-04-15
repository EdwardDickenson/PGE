#include "coordinate.hpp"

Coordinate::Coordinate()
{
	x = 0.0;
	y = 0.0;
}

Coordinate::Coordinate(double defaultX, double defaultY)
{
	x = defaultX;
	y = defaultY;
}

Coordinate::Coordinate(double coord)
{
	x = coord;
	y = coord;
}

Coordinate::Coordinate(unsigned int defaultX, unsigned int defaultY)
{

}

Coordinate::Coordinate(unsigned int coord)
{

}

Coordinate::Coordinate(string fromString)
{
	
}

double Coordinate::getRelX()
{
	return x;
}

double Coordinate::getRelY()
{
	return y;
}

void Coordinate::setX(double newX)
{
	x = newX;
}

void Coordinate::setY(double newY)
{
	y = newY;
}

void Coordinate::setXY(double newX, double newY)
{
	x = newX;
	y = newY;
}

void Coordinate::set(double newCoord)
{
	x = newCoord;
	y = newCoord;
}

void Coordinate::setX(unsigned int newX)
{

}

void Coordinate::setY(unsigned int newY)
{

}

void Coordinate::setXY(unsigned int newX, unsigned int newY)
{

}

void Coordinate::set(unsigned int coord)
{

}

void Coordinate::setString(string fromString)
{

}

double Coordinate::distance(Coordinate other)
{
	return sqrt(pow(x + other.x, 2) + pow(y + other.y, 2));
}

double Coordinate::slope(Coordinate other)
{
	return (y + other.y) / (x + other.x);
}

string Coordinate::toString()
{
	return "(" + to_string(x) + "," + to_string(y) + ")";
}
