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

class Object
{
public:
	Object();//Positions, Texture and Rotation are randomized in the constuctor
	~Object();
	int rotateAround;
	float totalPosX, totalPosY, totalPosZ;
	float posX, posY, posZ;
	float rotaX1, rotaY1, rotaZ1;
	float rotaX2, rotaY2, rotaZ2;
	float rotaSpeed;
	float size;
	float distanceToCamera;
	GLuint* texture;
	int lod;

	float GetDistanceToCamera(float cameraX, float cameraY, float cameraZ) const;
	void RecalculateLOD(float cameraX, float cameraY, float cameraZ);
	void SetTotalPosFromMatrix(float matrixX, float matrixY, float matrixZ);
	void draw(const float cameraX, const float cameraY, const float cameraZ);

private:
	int lod1Dist, lod2Dist;

	void drawSphere(int slices);
	void drawCube();
	void drawPyramid();
};

