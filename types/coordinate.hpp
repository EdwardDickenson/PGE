#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "../deps.hpp"

class Coordinate
{
private:

	double x;
	double y;

public:

	Coordinate();
	Coordinate(double defaultX, double defaultY);

	double getX();
	double getY();
	void setX(double newX);
	void setY(double newY);
	void setXY(double newX, double newY);
	void setXY(double newCoord);

	double distance(Coordinate other);
	double slope(Coordinate other);
};

#endif	//	COORDINATE_HPP



//	TODO:
//	This should be able to operate on more than two dimensional vectors, or
//	three dimensional, all the way up to n-th dimensional vectors.
//
//
