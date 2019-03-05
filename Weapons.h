#pragma once
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
	void BulletCheck();
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
