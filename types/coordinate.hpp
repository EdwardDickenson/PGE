#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "../deps.hpp"

class Coordinate
{
private:

	double x;
	double y;
	unsigned int position;

public:

	Coordinate();
	Coordinate(double defaultX, double defaultY);
	Coordinate(double coord);
	Coordinate(unsigned int defaultX, unsigned int defaultY);
	Coordinate(unsigned int coord);
	Coordinate(string fromString);

	double getRelX();
	double getRelY();
	int getX();
	int getY();
	int getXY();
	void setX(double newX);
	void setY(double newY);
	void setXY(double newX, double newY);
	void set(double coord); // Sets both x and y equal to newCoord
	void setX(unsigned int newX);
	void setY(unsigned int newY);
	void setXY(unsigned int newX, unsigned int newY);
	void set(unsigned int coord);
	void setString(string fromString);

	double distance(Coordinate other);
	double slope(Coordinate other);

	string toString();
};

#endif	//	COORDINATE_HPP



//	TODO:
//	This should be able to operate on more than two dimensional vectors, or
//	three dimensional, all the way up to n-th dimensional vectors.
//
//
