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
class Sun
{
public:
	Sun();
	~Sun();
	float rotaX1, rotaY1, rotaZ1;
	float rotaX2, rotaY2, rotaZ2;
	float rotaSpeed;
	float size;
	int texture;
};

