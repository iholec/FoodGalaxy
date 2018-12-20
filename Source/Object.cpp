#include "Object.h"
#include <cmath>


Object::Object()
{
	lod = 0;
	lod1Dist = 120;
	lod2Dist = 200;

	//Position
	posX = -4 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4 - (-4))));
	posY = -4 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4 - (-4))));
	posZ = -4 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4 - (-4))));

	//Rotation 1
	rotaX1 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaY1 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaZ1 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));

	//Rotation 2
	rotaX2 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaY2 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaZ2 = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));

	
	size = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.8 - 0.1)));
	rotaSpeed = 25 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (100 - 25)));
}

float Object::GetDistanceToCamera(const float cameraX, const float cameraY, float cameraZ) const
{
	return sqrt(pow(((totalPosX) - cameraX), 2) + pow(((totalPosY) - cameraY), 2) + pow(((totalPosZ) - cameraZ), 2));
}

void Object::RecalculateLOD(const float cameraX, const float cameraY, float cameraZ)
{
	distanceToCamera = GetDistanceToCamera(cameraX, cameraY, cameraZ);

	if (distanceToCamera < lod1Dist)
	{
		lod = 0;
	}
	else if (distanceToCamera > lod1Dist && distanceToCamera < lod2Dist)
	{
		lod = 1;
	}
	else {
		lod = 2;
	}
}


void Object::SetTotalPosFromMatrix(float matrixX, float matrixY, float matrixZ)
{
	totalPosX = matrixX;
	totalPosY = matrixY;
	totalPosZ = matrixZ;
}

//Draws the correct Mesh for the current distance to the camera (LOD)
void Object::draw(const float cameraX, const float cameraY, const float cameraZ)
{
	RecalculateLOD(cameraX, cameraY, cameraZ);
	switch (lod)
	{
	case 0:
		drawSphere(20);
		break;
	case 1:
		drawCube();
		break;
	case 2:
		drawPyramid();
		break;
	}

}

void Object::drawCube()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glBegin(GL_QUADS);
	// front face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f*size, 1.0f*size, 1.0f*size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f*size, 1.0f*size, 1.0f*size);
	// back face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f*size, 1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f*size, 1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f*size, -1.0f*size, -1.0f*size);
	// top face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f*size, 1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f*size, 1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f*size, 1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f*size, 1.0f*size, -1.0f*size);
	// bottom face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	// right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f*size, 1.0f*size, -1.0f*size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f*size, 1.0f*size, 1.0f*size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);
	// left face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f*size, 1.0f*size, 1.0f*size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f*size, 1.0f*size, -1.0f*size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Object::drawPyramid()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texture);

	glBegin(GL_TRIANGLES);
	glTexCoord3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f*size, 1.0f*size, 0.0f*size);
	glTexCoord3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);

	glTexCoord3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f*size, 1.0f*size, 0.0f*size);
	glTexCoord3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f*size, -1.0f*size, -1.0f*size);

	glTexCoord3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f*size, 1.0f*size, 0.0f*size);
	glTexCoord3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);


	glTexCoord3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f*size, -1.0f*size, 1.0f*size);
	glTexCoord3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f*size, -1.0f*size, -1.0f*size);
	glTexCoord3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f*size, -1.0f*size, 1.0f*size);

	glEnd();

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//draws a classic Sphere
void Object::drawSphere(int slices) {

	GLUquadric *qobj = gluNewQuadric();

	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, *texture);

	gluSphere(qobj, size, slices, 20);

	gluDeleteQuadric(qobj);
	glDisable(GL_TEXTURE_2D);
}

Object::~Object()
{
}
