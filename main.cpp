#include "deps.hpp"
#include <GLFW/glfw3.h>

#include "geometry/geometry.hpp"
#include "types/types.hpp"
#include "deps.hpp"

using namespace std;

string names[numberOfFunctions] = {	"render_chess_board",
			"render_growing_square",
			"render_bouncing_square",
			"render_square_image",
			"render_circle"};

//	Should be in a text file
string descriptions[] = {	"render_chess_board: Renders a red and black chess board of dimensions equal to the window",
							"render_growing_square: Renders a white square which expands to the edge of the screen and then shrinks back to darkness",
							"render_bouncing_square: Renders a white square which bounces across the screen leaving red dots where it collides with the edge",
							"render_square_image: Renders a square with an image"};

void print_descriptions()
{
	cout << "==========================================================" << endl;

	for(size_t i = 0; i < numberOfFunctions; ++i)
	{
		cout << descriptions[i] << endl;
	}

	cout << "==========================================================" << endl;
}

void cli()
{
	bool running = true;
	string input;

	while(running)
	{
		cout << "Input the name of a funciton(\"quit\" to end program or \"print_descriptions\" to see the function map): ";
		cin >> input;

		if(input == "quit" || input == "exit")
		{
			running = false;
		}

		if(input == "print_descriptions")
		{
				print_descriptions();
		}

		for(size_t i = 0; i < numberOfFunctions; ++i)
		{
			if(input == names[i])
			{
				functions[i]();
			}
		}
	}
}

int main(int argc, char *argv[])
{
	cout << "===\tStarting Program\t===" << endl;

	cli();

	cout << "===\tEnding Program\t\t===" << endl;

	return 0;
}



//	TODO:
//	The work required to make a square grow and shrink, like in the growing
//	square example, is greater than it may initially seem. Con sider writing a
//	grow/shrink function in this class.
//
//
