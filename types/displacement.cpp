#include "displacement.hpp"

Displacement::Displacement()
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
}
