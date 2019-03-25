#pragma once
#include <TL-Engine.h>
using namespace tle;

//This header contains assisstant functions and struct declarations

struct Vector3
{
	float posX;
	float posY;
	float posZ;
};

struct SHealthUI
{
	string hamName;
	ISprite* hamHealth;
};

namespace utility
{
	
	//
	double frameTime(double frameTime, I3DEngine* myEngine);	//Frame time calculation
	

	//
	int framesPerSecond(int frameTime);	//Number of frames in ONE second
	

	//
	bool getDistance(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad);

	//
	bool Delay(const float frameTimeFixed, float tickDelay);
}