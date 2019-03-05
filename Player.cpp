#include "Player.h"

CPlayer::CPlayer(IMesh* playerMesh, I3DEngine* myEngine, string name, int health, int amo)
{
	
	playerModel = playerMesh->CreateModel(0.0f, 5.0f, 0.0f);
	mEngine = myEngine;
	mName = name;
	mHealth = health;
	mAmo = amo;
}

void CPlayer::Move()
{
	if (mEngine->KeyHeld(Key_W))
	{
		playerModel->MoveZ(1);
		//mDummy->MoveZ(1);
	}
	if (mEngine->KeyHeld(Key_S))
	{
		playerModel->MoveZ(-1);
		//mDummy->MoveZ(-1);
	}
	if (mEngine->KeyHeld(Key_D))
	{
		playerModel->MoveX(1);
		//mDummy->MoveX(1);
	}
	if (mEngine->KeyHeld(Key_A))
	{
		playerModel->MoveX(-1);
		//mDummy->MoveX(-1);
	}
}

bool CPlayer::Shoot(IModel* dummyModel,deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr, int x, int y, int z)
{
	bulletPtr.reset(new CRifle(mEngine, "Cube.x", 1.0));
	bulletPtr->buildBullet(x, y, z);
	bulletPtr->bulletModel->LookAt(dummyModel);
	bulletList.push_back(move(bulletPtr));

	return true;
}

bool CPlayer::ClearBullet(IModel* dummyModel, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
	auto p = bulletList.begin();//pointer to beggining of the que 
	while (p != bulletList.end())
	{
		//collision detection with the perimiter wanted
		bool BulletOutRange = (*p)->getDistance(playerModel->GetX(), playerModel->GetZ(), 100.0f, (*p)->bulletModel->GetX(), (*p)->bulletModel->GetZ(), 2.0f);

		if (BulletOutRange == false)
		{
			(*p)->Delete();
			bulletList.erase(p);
			break;//quits the while loop if collision is detected
		}
		p++;
	}
	return true;
}