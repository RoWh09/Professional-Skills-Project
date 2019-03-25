#pragma once
#include "Utility.h"
#include <string>
#include <deque>
#include <TL-Engine.h>
using namespace tle;

class CRifle
{
private:
	I3DEngine* mEngine;
	int mSpeed;
public:
	IMesh* mMesh;
	CRifle(IMesh* bulletMesh, int speed);
	~CRifle(){};
	float bulletxPos;
	float bulletzPos;
	float bulletRad;
	IModel* bulletModel;
	bool buildBullet(int x, int y, int z);
	float GetPosition(float& x, float& z);
	void move(float speed);
	void Delete();
	void BulletCheck(float playerxPos, float playerzPos, float playerRad, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
	bool getDistance(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad);
};
