#include "draw.hpp"

void draw(Square &square)
{
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);
	glLoadIdentity();

	double length = square.getLength();
	Coordinate position = square.getPosition();
	rgbColor *color = square.getColor();
	double x = position.getX();
	double y = position.getY();

	glColor3d(color[0].red(), color[0].green(), color[0].blue());
	glTexCoord2d(x, y);
	glVertex2d(x, y);

	glColor3d(color[1].red(), color[1].green(), color[1].blue());
	glTexCoord2d(x - length, y);
	glVertex2d(x - length, y);

	glColor3d(color[2].red(), color[2].green(), color[2].blue());
	glTexCoord2d(x - length, y - length);
	glVertex2d(x - length, y - length);

	glColor3d(color[3].red(), color[3].green(), color[3].blue());
	glTexCoord2d(x, y - length);
	glVertex2d(x, y - length);

	glEnd();
}

void draw(Square *squares, size_t argc)
{
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);
	glLoadIdentity();

	double length;
	Coordinate position;
	rgbColor *color;
	double x;
	double y;

	for(size_t i = 0; i < argc; ++i)
	{
		length = squares[i].getLength();
		position = squares[i].getPosition();
		color = squares[i].getColor();
		x = position.getX();
		y = position.getY();

		glColor3d(color[0].red(), color[0].green(), color[0].blue());
		glTexCoord2d(x, y);
		glVertex2d(x, y);

		glColor3d(color[1].red(), color[1].green(), color[1].blue());
		glTexCoord2d(x - length, y);
		glVertex2d(x - length, y);

		glColor3d(color[2].red(), color[2].green(), color[2].blue());
		glTexCoord2d(x - length, y - length);
		glVertex2d(x - length, y - length);

		glColor3d(color[3].red(), color[3].green(), color[3].blue());
		glTexCoord2d(x, y - length);
		glVertex2d(x, y - length);
	}

	glEnd();
}

void draw(vector<Square> &squares)
{
	double length;
	double x;
	double y;
	int html;
	double xd; // X delta
	double yd; // Y delta
	Coordinate position;
	rgbColor *color;
	size_t size = squares.size();

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);
	glLoadIdentity();

	for(size_t i = 0; i < size; ++i)
	{
		Square tmp = squares[i];  // Not sure if this actually helps or not, but it reduces the number of accesses needed to the vector

		length = tmp.getLength();
		position = tmp.getPosition();
		color = tmp.getColor();
		x = position.getX();  // Would these two be a good case for pass by pointer?
		y = position.getY();

		xd = x - length;
		yd = y - length;

		html = color[0].HTML();

		glColor3d(double(((html & 16711680) >> 16) / 255), double(((html & 65280) >> 8) / 255), double(((html & 255)) / 255));
		glTexCoord2d(x, y);
		glVertex2d(x, y);

		html = color[1].HTML();

		glColor3d(double(((html & 16711680) >> 16) / 255), double(((html & 65280) >> 8) / 255), double(((html & 255)) / 255));
		glTexCoord2d(xd, y);
		glVertex2d(xd, y);

		html = color[2].HTML();

		glColor3d(double(((html & 16711680) >> 16) / 255), double(((html & 65280) >> 8) / 255), double(((html & 255)) / 255));
		glTexCoord2d(xd, yd);
		glVertex2d(xd, yd);

		html = color[3].HTML();

		glColor3d(double(((html & 16711680) >> 16) / 255), double(((html & 65280) >> 8) / 255), double(((html & 255)) / 255));
		glTexCoord2d(x, yd);
		glVertex2d(x, yd);
	}

	glEnd();
}

void draw(Circle &circle)
{
	//glBegin(GL_LINE_LOOP);
	glBegin(GL_TRIANGLE_FAN);

	double pi = 3.141592654;
	double radius = circle.getRadius();
	double x = circle.getPosition().getX();
	double y = circle.getPosition().getY();

	// The reason why the following code is commented out is because I am not
	// certain if rendering the circle with radians or degrees is faster, and I
	// need to include some bechmarking facilities.

	// Additionally, I should be able to create circle by only using one
	// quadrant and then rotate that accross axies.

	/*double radian = 3.141592654 / 180;
	double radius = circle.getRadius();

	for(int i = 0; i < 360; ++i)
	{
		double position = i * radian;
		glVertex2d(cos(position) * radius, sin(position) * radius);
	}*/

	for(double i = 0; i < 2 * pi; i += .125)
	{
		// Possibly we can include an x/y bias for non square windows
		glVertex2d(cos(i) * radius + x, sin(i) * radius + y);
	}

	glEnd();
}

void draw(Circle *circle, int argc)
{
	glBegin(GL_TRIANGLE_FAN);

	double pi = 3.141592654;

	for(int j = 0; j < argc; ++j)
	{
		double radius = circle[j].getRadius();
		double x = circle[j].getPosition().getX();
		double y = circle[j].getPosition().getY();

		for(double i = 0; i < 2 * pi; i += .125)
		{
			glVertex2d(cos(i) * radius + x, sin(i) * radius + y);
		}
	}

	glEnd();
}

/*void draw()
{

}*/
