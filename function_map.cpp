#include "draw.hpp"
#include "types/types.hpp"

double rate = .00390625;	//	1/256 or 2^-8
int texture[1];

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
        if((key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) || (key == GLFW_KEY_Q && action == GLFW_PRESS))
        {
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
}

void bouncing_controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if((key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) || (key == GLFW_KEY_Q && action == GLFW_PRESS))
	{
			glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if(key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
	{
			rate *= 2;
	}

	if(key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
	{
			rate /= 2;
	}
}

int LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
{
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture(name.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    if(texture[0] == 0)
	{
        return false;
	}

    glBindTexture(GL_TEXTURE_2D, texture[0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    return true;
}

void render_color_combinations()
{
	size_t W = 800;
	size_t H = 800;

	rgbColor red(0, 0, 0);
	rgbColor green(0, 0, 0);
	rgbColor blue(0, 0, 0);

	Square redSquare(.5, Coordinate(-.25, .5));
	Square greenSquare(.5, Coordinate(.25, .5));
	Square blueSquare(.5, Coordinate(.75, .5));

	if(!glfwInit())
	{
		cout << "Error initilizing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	window = glfwCreateWindow(W, H, "Primitives - Render Color Combinations", NULL, NULL);
	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
		for(int i = 0; i < 255; ++i)
		{
			for(int j = 0; j < 255; ++j)
			{
				for(int k = 0; k < 255; ++k)
				{
					glClear(GL_COLOR_BUFFER_BIT);

					red.setHTMLRed(i);
					green.setHTMLGreen(j);
					blue.setHTMLBlue(k);

					redSquare.setColor(red);
					greenSquare.setColor(green);
					blueSquare.setColor(blue);

					draw(redSquare);
					draw(greenSquare);
					draw(blueSquare);

					glfwSwapBuffers(window);
					glfwPollEvents();

					//	These three conditions are doing effectively the same thing as the while loop conditions.
					//	Essentially, what's going on here is a cascading break statement for all three loops.
					//	In the future, there should be an exit condition function which is tested.  This
					//	will be implemented when the window functionality is encapsulated.
					if(glfwWindowShouldClose(window))
					{
						break;
					}
				}

				if(glfwWindowShouldClose(window))
				{
					break;
				}
			}

			if(glfwWindowShouldClose(window))
			{
				break;
			}
		}
	}

		glfwDestroyWindow(window);
		glfwTerminate();
}

void render_circle()
{
		if(!glfwInit())
		{
			cout << "Error initializing GLFW" << endl;

			return;
		}

		GLFWwindow *window;
		size_t W = 800;
		size_t H = 800; // Aspect ratio is an issue when we render circles in a
						// window that is not square. Aspect ratio and scaling
						// are in general issues that we have yet to address.

		window = glfwCreateWindow(W, H, "Primitives - Render Circle", NULL, NULL);

		glfwSetKeyCallback(window, controls);
		glfwMakeContextCurrent(window);

		Circle circle(.1, Coordinate(.5, .5));

		while(!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			draw(circle);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
}

void render_square_image()
{
	if(!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	size_t W = 800;
	size_t H = 800;

	window = glfwCreateWindow(W, H, "primitives - Square Image", NULL, NULL);

	glfwSetKeyCallback(window, bouncing_controls);
	glfwMakeContextCurrent(window);

	Square block(1, Coordinate(1.0, 1.0), rgbColor(1.0, 1.0, 1.0));

	string fname;
	cout << "Input the name of an image file: ";
	cin >> fname;
	LoadGLTextures(fname);

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		draw(block);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void render_bouncing_square()
{
	if(!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	size_t W = 800;
	size_t H = 800;

	window = glfwCreateWindow(W, H, "Primitives - Bouncing Square", NULL, NULL);

	glfwSetKeyCallback(window, bouncing_controls);
	glfwMakeContextCurrent(window);

	double length = .1;
	double point_length = length / 10;
	Coordinate origin(-1 + length, 1);
	Square block(length, origin);

	double xDisp = rate * 4;
	double yDisp = rate;

	vector<Square> points;

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT); // Maybe this should be in corporated into the draw function
		draw(block);
		origin.setX(origin.getRelX() + xDisp);
		origin.setY(origin.getRelY() - yDisp);
		block.setPosition(origin);

		if(origin.getRelX() > 1)
		{
				xDisp = -xDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getRelX() - point_length * 2, block.getPosition().getRelY()), rgbColor(255, 0, 0)));
				cout << points.size() << endl;
		}

		if(origin.getRelY() > 1)
		{
				yDisp = -yDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getRelX(), block.getPosition().getRelY() - point_length * 2), rgbColor(255, 0, 0)));
				cout << points.size() << endl;
		}

		if(origin.getRelX() - length < -1)
		{
				xDisp = -xDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getRelX(), block.getPosition().getRelY()), rgbColor(255, 0, 0)));
				cout << points.size() << endl;
		}

		if(origin.getRelY() - length < -1)
		{
				yDisp = -yDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getRelX(), block.getPosition().getRelY()), rgbColor(255, 0, 0)));
				cout << points.size() << endl;
		}

		draw(points);

		glFlush();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void render_growing_square()
{
	if(!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	size_t W = 800;
	size_t H = 800;

	window = glfwCreateWindow(W, H, "Primitives - Growing Square", NULL, NULL);
	glfwSwapInterval(0);

	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	double length = rate;

	Coordinate origin(length / 2, length / 2);
	Square block(length, origin);
	bool grow = true;

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		draw(block);

		block.resize(length);

		if(grow)
		{
			length += 0.00390625;
		}

		else
		{
			length -= 0.00390625;
		}

		if(length == 2 || length == 0)
		{
			grow = !grow;
		}

		//glFinish();
		//glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void render_chess_board()
{
	if(!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	size_t W = 800;
	size_t H = 800;

	glfwSwapInterval(0);
	//#define _GLFW_USE_DWM_SWAP_INTERVAL 0
	window = glfwCreateWindow(W, H, "Primitives - Chess Board", NULL, NULL);

	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	vector<Square> squares;
	double length_of_square = pow(2, -2);
	double xPos;
	double yPos = 1;
	bool offset = false;

	int n = 0;

	while(yPos >= -1)
	{
		xPos = -1;

		if(offset)
		{
			xPos += length_of_square;
		}

		while(xPos <= 1)
		{
			squares.push_back(Square(length_of_square, Coordinate(xPos, yPos), rgbColor(1.0, 0.0, 0.0)));
			xPos += (length_of_square * 2);
			++n;
		}

		offset = !offset;
		yPos -= length_of_square;
	}

	cout << "Created a total of: " << n << " Squares" << endl;

	unsigned int fps = 0;
	double seconds = glfwGetTime();

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		draw(squares);

		glfwSwapBuffers(window);
		glfwPollEvents();

		++fps;

		if(glfwGetTime() - seconds >= 1.0)
		{
			cout << "Frames per second: " << fps << endl;
			fps = 0;
			seconds = glfwGetTime();
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void(*functions[numberOfFunctions])() = {
											&render_chess_board,
											&render_growing_square,
											&render_bouncing_square,
											&render_square_image,
											&render_circle,
											&render_color_combinations};



//	TODO:
//
//
//
