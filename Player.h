#pragma once
#include "Weapons.h"
#include <string>
#include "TL-Engine.h"
#include <TL-Engine.h>
using namespace tle;

//Base Clasee for the player
class CPlayer
{
private:
	I3DEngine* mEngine;
	string mName;
	int mHealth;
	int mAmo;

public:
	IModel* playerModel;
	CPlayer(IMesh* playerMesh ,I3DEngine* myEngine, string name, int health, int amo);
	void Move();
	bool Shoot(IModel* dummyModel, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr, int x, int y, int z);
	bool ClearBullet(IModel* dummyModel, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
};

