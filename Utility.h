#pragma once
#include "TL-Engine.h"
using namespace tle;

//This header contains assisstant functions and struct declarations

struct Vector3
{
	float posX;
	float posY;
	float posZ;
};

namespace utility
{
	double frameTime;	//Frametime decleared here

	//
	double frameTime(double frameTime, I3DEngine* myEngine)	//Frame time calculation
	{
		return frameTime = myEngine->Timer();
	}
	
	//
	int framesPerSecond()	//Number of frames in ONE second
	{
		return 1 / frameTime;
	}

	//
	float getDistance(IModel* player, IModel* object)	//Returns the distance between two models
	{
		float playerX = player->GetX();
		float playerZ = player->GetZ();

		float objectX = object->GetX();
		float objectZ = object->GetZ();

		float temp1 = (playerX - objectX) * (playerX - objectX);
		float temp2 = (playerZ - objectZ) * (playerZ - objectZ);

		return sqrt(temp1 + temp2);
	}
}
