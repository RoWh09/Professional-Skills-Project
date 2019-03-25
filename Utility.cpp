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
bool utility::getDistance(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad)
{
	float distX = s2xPos - s1xPos;
	float distZ = s2zPos - s1zPos;
	float distance = sqrt(distX*distX + distZ * distZ);

	return (distance < (s1rad + s2rad));
}

bool utility::Delay(const float frameTimeFixed, float tickDelay)
{
	static float counterFrame = 0.0f;

	counterFrame += frameTimeFixed;

	if (counterFrame > tickDelay)
	{
		counterFrame = 0;
		return true;
	}
	return false;
}