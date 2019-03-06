#include "Utility.h"


double utility::frameTime(double frameTime, I3DEngine* myEngine)	//Frame time calculation
{
	return frameTime = myEngine->Timer();
}

//
int utility::framesPerSecond(int frameTime)	//Number of frames in ONE second
{
	return 1 / frameTime;
}

//
bool utility::SphereCollision(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad)
{
	float distX = s2xPos - s1xPos;
	float distZ = s2zPos - s1zPos;
	float distance = sqrt(distX*distX + distZ * distZ);

	return (distance < (s1rad + s2rad));
}

float utility::getDistance(IModel* player, IModel* object)	//Returns the distance between two models
	{
		float playerX = player->GetX();
		float playerZ = player->GetZ();

		float objectX = object->GetX();
		float objectZ = object->GetZ();
	int framesPerSecond(int frameTime);	//Number of frames in ONE second


		float temp1 = (playerX - objectX) * (playerX - objectX);
		float temp2 = (playerZ - objectZ) * (playerZ - objectZ);
	//
	bool getDistance(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad);

		return sqrt(temp1 + temp2);
	}
