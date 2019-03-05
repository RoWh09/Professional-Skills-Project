#pragma once
#include "Utility.h"
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <deque>
using namespace tle;

class CRifle
{
private:
	int mSpeed;
	IMesh* bulletMesh;
public:
	CRifle(I3DEngine* myEngine, string meshName, int speed);
	~CRifle(){};
	float bulletxPos;
	float bulletzPos;
	float bulletRad;
	IModel* bulletModel;
	bool buildBullet(int x, int y, int z);
	float GetPosition(float& x, float& z);
	void move(int speed);
	void Delete();
	void BulletCheck(float playerxPos, float playerzPos, float playerRad, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
};

//initialising the game with the existing tlEngine and the wanted speed of the bullet
CRifle::CRifle(I3DEngine* myEngine, string meshName, int speed)
{
	bulletMesh = myEngine->LoadMesh(meshName);
	mSpeed = speed;
}

//Creating an instance of the bullet
bool CRifle::buildBullet(int x, int y, int z)
{
	bulletModel = bulletMesh->CreateModel(x, y, z);
	return bulletModel;
}

//Gets the spwaing position of the bullet
float CRifle::GetPosition(float& x, float& z)
{
	x = bulletModel->GetX();
	z = bulletModel->GetZ();
	return x, z;
}

//Moving the bullet foward
void CRifle::move(int speed)
{
	bulletModel->MoveLocalZ(speed);
}

//Delte the bulletModel
void CRifle::Delete()
{
	bulletMesh->RemoveModel(bulletModel);
}


void CRifle::BulletCheck(float playerxPos, float playerzPos, float playerRad, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
	auto p = bulletList.begin();
	while (p != bulletList.end())
	{
		(*p)->GetPosition(bulletxPos, bulletzPos);
		bool BulletOutRange = utility::getDistance(playerxPos, playerzPos, playerRad, bulletxPos, bulletzPos, 2.0f);

		if (BulletOutRange == false)
		{
			(*p)->Delete();
			bulletList.erase(p);
			break;
		}
		p++;
	}
}
