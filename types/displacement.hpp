#ifndef DISPLACEMENT_HPP
#define DISPLACEMENT_HPP

#include <math.h>

class Displacement
{
private:

	double i;
	double j;

public:

	Displacement();
	Displacement(double defaultI, double defaultJ);

	double getI();
	double getJ();
	void setI(double newI);
	void setJ(double newJ);

	double magnitude();
	double dot(Displacement other);
	Displacement unitV();

	void add(Displacement addend);
	void multiply(double multiplicand);
};

/*Displacement::Displacement()
{
	i = 0;
	j = 0;
}

Displacement::Displacement(double defaultI, double defaultJ)
{
	i = defaultI;
	j = defaultJ;
}

double Displacement::getI()
{
	return i;
}

double Displacement::getJ()
{
	return j;
}

void Displacement::setI(double newI)
{
	i = newI;
}

void Displacement::setJ(double newJ)
{
	j = newJ;
}

double Displacement::magnitude()
{
	return sqrt(pow(i, 2) + pow(j, 2));
}

double Displacement::dot(Displacement other)
{
	return (i + other.i) + (j + other.j);
}

void Displacement::add(Displacement other)
{
	i += other.i;
	j += other.j;
}*/

#endif	//	DISPLACEMENT_HPP



//	TODO:
//
//	Same as the coordinate class, this should be expanded to include more
//	dimensions.  But for now 2d/3d is fine.
//
//	Note that this class mixes mutable and immutable functions. This is not
//	ideal, but it is probably fine for whatever I am working with.
//
//
//
