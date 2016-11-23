#include "square.hpp"

Square::Square()
{
	length = 0;

	position.setX(0);
	position.setY(0);

	rgbColor tmp(1.0, 1.0, 1.0);
	color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition)
{
	length = defaultLength;
	position = defaultPosition;

	rgbColor tmp(1.0, 1.0, 1.0);
	color[0] = tmp;
	color[1] = tmp;
	color[2] = tmp;
	color[3] = tmp;
}

Square::Square(double defaultLength, Coordinate defaultPosition, rgbColor defaultColor)
{
	length = defaultLength;
	position = defaultPosition;

	color[0] = defaultColor;
	color[1] = defaultColor;
	color[2] = defaultColor;
	color[3] = defaultColor;
}

double Square::getLength()
{
	return length;
}

/*Coordinate Square::getPosition()
{
	return position;
}*/

rgbColor *Square::getColor()
{
	return color;
}

void Square::setLength(double newLength)
{
	length = newLength;
}

//	Set the position of the upper right hand corner
/*void Square::setPosition(Coordinate newPosition)
{
	position = newPosition;
}*/

/*inline double Square::volume()
{
	return length * length;
}*/

void Square::draw()
{
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);
	glLoadIdentity();

	glColor3d(color[0].getR(), color[0].getG(), color[0].getB());
	glTexCoord2d(position.getX(), position.getY());
	glVertex2d(position.getX(), position.getY());

	glColor3d(color[1].getR(), color[1].getG(), color[1].getB());
	glTexCoord2d(position.getX() - length, position.getY());
	glVertex2d(position.getX() - length, position.getY());

	glColor3d(color[2].getR(), color[2].getG(), color[2].getB());
	glTexCoord2d(position.getX() - length, position.getY() - length);
	glVertex2d(position.getX() - length, position.getY() - length);

	glColor3d(color[3].getR(), color[3].getG(), color[3].getB());
	glTexCoord2d(position.getX(), position.getY() - length);
	glVertex2d(position.getX(), position.getY() - length);

	glEnd();
}
