#pragma once
#include "Weapons.h"
#include "Utility.h"
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
	int mAmo;

public:
	int mHealth;
	IModel* playerModel;
	CPlayer(deque <unique_ptr < SHealthUI > >& healthList, unique_ptr<SHealthUI>&healthPtr, IMesh* playerMesh ,I3DEngine* myEngine, string name, int health, int amo);
	void Move(float frameRate);
	void Damage(I3DEngine* myEngine, deque <unique_ptr < CRifle > >& bulletList, deque <unique_ptr < SHealthUI > >& healthList);
	bool Shoot(IModel* dummyModel, IMesh* bulletMesh, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>& bulletPtr, int x, int y, int z);
	bool ClearBullet(IModel* dummyModel, deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
};

