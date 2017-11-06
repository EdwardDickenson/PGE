#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "../deps.hpp"

class Coordinate
{
private:

	double x;
	double y;
	unsigned int position;

	//
	//unsigned int width;	//	Should also be 16-bit
	//unsigned int height;	//	Should also be 16-bit

public:

	//	Constructors
	Coordinate();
	Coordinate(double defaultX, double defaultY);
	Coordinate(double coord);
	Coordinate(unsigned int defaultX, unsigned int defaultY);
	Coordinate(unsigned int coord);
	//Coordinate(unsigned int defaultX, unsigned int defaultY, unsigned int defaultHeight, unsigned int defaultWidth);
	Coordinate(string fromString);

	//	Accessors
	double getRelX();
	double getRelY();
	int getX();	//	These should all be unsigned ints as well
	int getY();
	int getXY();
	//unsigned int getWidth();
	//unsigned int getHeight();

	//	Mutators
	void setX(double newX);
	void setY(double newY);
	void setXY(double newX, double newY);
	void set(double coord); // Sets both x and y equal to newCoord
	void setX(unsigned int newX);
	void setY(unsigned int newY);
	void setXY(unsigned int newX, unsigned int newY);
	void set(unsigned int coord);
	void setString(string fromString);

	//	Operators
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
