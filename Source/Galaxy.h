#pragma once
#ifdef __APPLE__
#include <GLUT/glut.h> 
#include <OpenGL/gl.h>  
#include <OpenGL/glu.h>  
#else
#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  
#endif
#include "Object.h"


class Galaxy
{
public:
	//Positions are randomized in the Constructor
	Galaxy();
	~Galaxy();
	float centerX, centerY, centerZ;
	float rotaX, rotaY, rotaZ;
	//Contains all Planets	
	Object planets[10];
};