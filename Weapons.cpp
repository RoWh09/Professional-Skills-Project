#include "Weapons.h"

//initialising the game with the existing tlEngine and the wanted speed of the bullet
CRifle::CRifle(IMesh* bulletMesh, int speed)
{
	mMesh = bulletMesh;
	mSpeed = speed;
}

//Creating an instance of the bullet
bool CRifle::buildBullet(int x, int y, int z)
{
	bulletModel = mMesh->CreateModel(x, y, z);
	bulletModel->SetSkin("red.PNG");
	return true;
}

//Gets the spwaing position of the bullet
float CRifle::GetPosition(float& x, float& z)
{
	x = bulletModel->GetX();
	z = bulletModel->GetZ();
	return x, z;
}

//Moving the bullet foward
void CRifle::move(float frameTime)
{
	float speed = 1000.0f;
	bulletModel->MoveLocalZ(speed * frameTime);
}

//Delte the bulletModel
void CRifle::Delete()
{
	mMesh->RemoveModel(bulletModel);
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

bool CRifle::getDistance(float s1xPos, float s1zPos, float s1rad, float s2xPos, float s2zPos, float s2rad)
{
	float distX = s2xPos - s1xPos;
	float distZ = s2zPos - s1zPos;
	float distance = sqrt(distX*distX + distZ * distZ);

	return (distance < (s1rad + s2rad));
}