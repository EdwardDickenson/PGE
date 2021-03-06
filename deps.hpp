#ifndef DEPS_HPP
#define DEPS_HPP

// C++ includes
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>

// C includes
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "limits.h"

// OpenGL includes
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

using namespace std;

static const size_t numberOfFunctions = 6;
extern void(*functions[numberOfFunctions])();

#endif	//	DEPS_HPP



//	TODO:
//
//
//
