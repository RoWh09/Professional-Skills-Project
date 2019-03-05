#pragma once
#include <string>
#include "Weapons.h"
#include "TL-Engine.h"
#include <TL-Engine.h>
using namespace tle;

//Base Clasee for the player
class CPlayer
{
private:
	I3DEngine* mEngine;
	IModel* playerModel;
	IModel* mDummy;
	string mName;
	int mHealth;
	int mAmo;

public:
	CPlayer(IModel* dummy, IModel* player, I3DEngine* myEngine, string name, int health, int amo);
	void Move();
	void Shoot(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
};

CPlayer::CPlayer (IModel* dummy, IModel* player, I3DEngine* myEngine, string name, int health, int amo)
{
	playerModel = player;
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
		mDummy->MoveZ(1);
	}
	if (mEngine->KeyHeld(Key_S))
	{
		playerModel->MoveZ(-1);
		mDummy->MoveZ(-1);
	}
	if (mEngine->KeyHeld(Key_D))
	{
		playerModel->MoveX(1);
		mDummy->MoveX(1);
	}
	if (mEngine->KeyHeld(Key_A))
	{
		playerModel->MoveX(-1);
		mDummy->MoveX(-1);
	}
}

void CPlayer::Shoot(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
		bulletPtr.reset(new CRifle(mEngine, "cube.x", 1.0));
		bulletPtr->buildBullet(playerModel->GetX(), playerModel->GetY(), playerModel->GetZ());
		bulletPtr->bulletModel->LookAt(mDummy);
		bulletList.push_back(move(bulletPtr));
}