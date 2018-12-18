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
	float totalPosX, totalPosY, totalPosZ;
	float distanceToCam;
	float rotaX, rotaY, rotaZ;
	//Contains all Planets	
	Object planets[10];

	float GetDistanceToCamera(float cameraX, float cameraY, float cameraZ);
	void SetTotalPosFromMatrix(float matrixX, float matrixY, float matrixZ);
};