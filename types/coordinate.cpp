#include "coordinate.hpp"

Coordinate::Coordinate()
{
	x = 0;
	y = 0;
}

Coordinate::Coordinate(double defaultX, double defaultY)
{
	x = defaultX;
	y = defaultY;
}

double Coordinate::getX()
{
	return x;
}

double Coordinate::getY()
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

// Yes, there is some copy & paste code here, but it is so low level that it will not cause issues
void Coordinate::setXY(double newX, double newY)
{
	x = newX;
	y = newY;
}

void Coordinate::setYX(double newY, double newX)
{
	y = newY;
	x = newX;
}

void Coordinate::set(double newCoord)
{
	x = newCoord;
	y = newCoord;
}

double Coordinate::distance(Coordinate other)
{
	return sqrt(pow(x + other.x, 2) + pow(y + other.y, 2));
}

double Coordinate::slope(Coordinate other)
{
	return (y + other.y) / (x + other.x);
}
