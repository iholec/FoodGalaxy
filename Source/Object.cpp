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


void Object::RecalculateTotalPosFromMatrix(float galaxyX, float galaxyY, float galaxyZ)
{
	totalPosX = galaxyX;
	totalPosY = galaxyY;
	totalPosZ = galaxyZ;
}


Object::~Object()
{
}
