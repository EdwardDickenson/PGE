#ifndef RESOLUTION_HPP
#define RESOLUTION_HPP

#pragma once

class Resolution
{
private:

	double width;
	double height;

public:

	Resolution();
	Resolution(double defaultWidth, double defaultHeight);

	void setWidth(double newWidth);
	void setHeight(double newHeight);
	double getWidth();
	double getHeight();

	double size();
};

/*Resolution::Resolution()
{
	width = 0;
	height = 0;
}

Resolution::Resolution(double defaultWidth, double defaultHeight)
{
	width = defaultWidth;
	height = defaultHeight;
}

void Resolution::setWidth(double newWidth)
{
	width = newWidth;
}

void Resolution::setHeight(double newHeight)
{
	height = newHeight;
}

double Resolution::getWidth()
{
	return width;
}

double Resolution::getHeight()
{
	return height;
}

double Resolution::size()
{
	return width * height;
}*/

#endif	//	RESOLUTION_HPP



//	TODO:
//
//	Add a scaling function
//
//
