#include "Galaxy.h"
#include <cmath>

Galaxy::Galaxy()
{
	//Position
	centerX = -25 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (25 - (-25))));
	centerY = -25 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (25 - (-25))));
	centerZ = -25 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (25 - (-25))));

	//Rotation
	rotaX = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaY = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
	rotaZ = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0)));
}
Galaxy::~Galaxy() {

}

//Calculate current distance to camera for sorting for transparency
float Galaxy::GetDistanceToCamera(const float cameraX, const float cameraY, float cameraZ)
{
	distanceToCam = sqrt(pow(((totalPosX)-cameraX), 2) + pow(((totalPosY)-cameraY), 2) + pow(((totalPosZ)-cameraZ), 2));
	return distanceToCam;
}


void Galaxy::SetTotalPosFromMatrix(float matrixX, float matrixY, float matrixZ)
{
	totalPosX = matrixX;
	totalPosY = matrixY;
	totalPosZ = matrixZ;
}
