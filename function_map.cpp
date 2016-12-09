#include "draw.hpp"
#include "types/types.hpp"

double rate = .00390625;
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

    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);

	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, MODE, GL_UNSIGNED_BYTE, BUFFER1);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    return true;
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

	Square block(1, Coordinate(1, 1), rgbColor(1.0, 1.0, 1.0));

	string fname;
	cout << "Input the name of an image file: ";
	cin >> fname;
	LoadGLTextures(fname);

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//glBindTexture(GL_TEXTURE_2D, texture[0]);
		//block.setPosition(Coordinate(block.getPosition().getX(), block.getPosition().getY() - .01));
		//block.draw();
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
		glClear(GL_COLOR_BUFFER_BIT);
		draw(block);
		origin.setX(origin.getX() + xDisp);
		origin.setY(origin.getY() - yDisp);
		block.setPosition(origin);

		if(origin.getX() > 1)
		{
				xDisp = -xDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getX() - point_length * 2, block.getPosition().getY()), rgbColor(1.0, 0.0, 0.0)));
				cout << points.size() << endl;
		}

		if(origin.getY() > 1)
		{
				yDisp = -yDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getX(), block.getPosition().getY() - point_length * 2), rgbColor(1.0, 0.0, 0.0)));
				cout << points.size() << endl;
		}

		if(origin.getX() - length < -1)
		{
				xDisp = -xDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getX(), block.getPosition().getY()), rgbColor(1.0, 0.0, 0.0)));
				cout << points.size() << endl;
		}

		if(origin.getY() - length < -1)
		{
				yDisp = -yDisp;
				points.push_back(Square(point_length, Coordinate(block.getPosition().getX(), block.getPosition().getY()), rgbColor(1.0, 0.0, 0.0)));
				cout << points.size() << endl;
		}

		draw(points);

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

	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	double length = rate;

	Coordinate origin(length / 2, length / 2);
	Square block(length, origin);
	bool grow = true;

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//block.draw();
		draw(block);

		//origin.setX(length / 2);
		//origin.setY(length / 2);
		//block.setPosition(origin);
		//block.setLength(length);

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

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

/*void render_chess_board()
{
	if(!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;

		return;
	}

	GLFWwindow *window;
	size_t W = 800;
	size_t H = 800;

	window = glfwCreateWindow(W, H, "Primitives - Chess Board", NULL, NULL);

	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	double length_of_square = .1;
	double n = (1 / length_of_square) * 2;

	vector<Square> squares;

	double initialX = 1;
	double initialY = 1;
	bool render = true;

	rgbColor colors[4] = {rgbColor(1.0, 0.0, 0.0), rgbColor(.5, 0.0, 0.0), rgbColor(.25, 0.0, 0.0), rgbColor(1.0, 0.0, 0.0)};

	for(int i = 0; i < n; ++i)
	{
		if(render)
		{
			initialX -= .1;
		}

		for(int j = 0; j < n; ++j)
		{
			Square square(length_of_square, Coordinate(initialX, initialY), colors);
			//Square square(length_of_square, Coordinate(initialX, initialY), rgbColor(1.0, 0.0, 0.0));
			squares.push_back(square);

			initialX -= .2;
		}

		initialX = 1;
		initialY -= .1;
		render = !render;
	}

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//for(int i = 0; i < n*n; ++i)
		//{
			//squares[i].draw();
			draw(squares);
		//}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}*/

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

	window = glfwCreateWindow(W, H, "Primitives - Chess Board", NULL, NULL);

	glfwSetKeyCallback(window, controls);
	glfwMakeContextCurrent(window);

	double length_of_square = .01;

	vector<Square> squares;
	double xPos = -1;
	double yPos = 1;
	bool offset = false;

	//rgbColor colors[4] = {rgbColor(1.0, 0.0, 0.0), rgbColor(.5, 0.0, 0.0), rgbColor(.25, 0.0, 0.0), rgbColor(1.0, 0.0, 0.0)};
	rgbColor colors[4] = {rgbColor(1.0, 0.0, 0.0), rgbColor(1.0, 0.0, 0.0), rgbColor(1.0, 0.0, 0.0), rgbColor(1.0, 0.0, 0.0)};

	while(yPos >= -1)
	{
		xPos = -1;

		if(offset)
		{
			xPos += length_of_square;
		}

		while(xPos <= 1)
		{
			squares.push_back(Square(length_of_square, Coordinate(xPos, yPos), colors));
			xPos += (length_of_square * 2);
		}

		offset = !offset;
		yPos -= length_of_square;
	}

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		draw(squares);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}



void(*functions[numberOfFunctions])() = {
											&render_chess_board,
											&render_growing_square,
											&render_bouncing_square,
											&render_square_image,
											&render_circle};



//	TODO:
//
//
//
