#include "Player.h"

CPlayer::CPlayer(deque <unique_ptr < SHealthUI > >& healthList, unique_ptr<SHealthUI>&healthPtr, IMesh* playerMesh, I3DEngine* myEngine, string name, int health, int amo)
{
	healthPtr.reset(new SHealthUI);
	for (int i = 200; i >= 0; i)
	{
		healthPtr->hamHealth = myEngine->CreateSprite("ham.png", i, .0f, .0f);
		healthList.push_back(move(healthPtr));
		healthPtr.reset(new SHealthUI);
		i -= 100;
	}
	playerModel = playerMesh->CreateModel(0.0f, 5.0f, 0.0f);
	mEngine = myEngine;
	mName = name;
	mHealth = health;
	mAmo = amo;
}

void CPlayer::Move(float frameRate)
{
	float speed = 100.0;
	if (mEngine->KeyHeld(Key_W))
	{
		playerModel->MoveZ(speed * frameRate);
		//mDummy->MoveZ(1);
	}
	if (mEngine->KeyHeld(Key_S))
	{
		playerModel->MoveZ(-(speed * frameRate));
		//mDummy->MoveZ(-1);
	}
	if (mEngine->KeyHeld(Key_D))
	{
		playerModel->MoveX(speed * frameRate);
		//mDummy->MoveX(1);
	}
	if (mEngine->KeyHeld(Key_A))
	{
		playerModel->MoveX(-(speed * frameRate));
		//mDummy->MoveX(-1);
	}
}

void CPlayer::Damage(I3DEngine* myEngine, deque <unique_ptr < CRifle > >& bulletList, deque <unique_ptr < SHealthUI > >& healthList)
{
	auto p = bulletList.begin();
	auto j = healthList.begin();
	while (p != bulletList.end())
	{
		bool hit = utility::getDistance(playerModel->GetX(), playerModel->GetZ(), 5.0f, (*p)->bulletModel->GetX(), (*p)->bulletModel->GetZ(), 2.0f);
		if (hit == true)
		{
			if (mHealth <= 0)
			{

			}
			else
			{
				myEngine->RemoveSprite((*j)->hamHealth);
				healthList.erase(j);
				(*p)->Delete();
				bulletList.erase(p);
			    mHealth -= 1;
				break;
			}
		}
		++p;
	}
}

bool CPlayer::Shoot(IModel* dummyModel, IMesh* bulletMesh, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>& bulletPtr, int x, int y, int z)
{
	bulletPtr.reset(new CRifle(bulletMesh, 1.0));
	bulletPtr->buildBullet(x, y, z);
	bulletPtr->bulletModel->LookAt(dummyModel);
	bulletPtr->bulletModel->SetSkin("ham.png");
	bulletPtr->bulletModel->Scale(0.2);
	bulletList.push_back(move(bulletPtr));

	return true;
}

bool CPlayer::ClearBullet(IModel* dummyModel, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
	auto p = bulletList.begin();//pointer to beggining of the que 
	while (p != bulletList.end())
	{
		//collision detection with the perimiter wanted
		bool BulletOutRange = (*p)->getDistance(playerModel->GetX(), playerModel->GetZ(), 300.0f, (*p)->bulletModel->GetX(), (*p)->bulletModel->GetZ(), 2.0f);

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