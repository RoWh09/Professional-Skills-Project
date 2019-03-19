#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include "Weapons.h"
#include "Utility.h"
#include "EnemiesInterface.h"
using namespace tle;

class CMarine : IEnemy
{
private:
	IMesh* mMesh;
	deque <unique_ptr < CRifle > > bulletList;
	unique_ptr<CRifle>bulletPtr;
	float moveSpeed = 5.0f;
	float fireDistance = 8.0f;		//How far can he start to shoot?
	float fleeDistance = 4.0f;		//Will flee if too close
	float xPos;
	float zPos;
	float mRad;

public:
	int health = 3;
	IModel* marineModel;
	CMarine(IMesh* marineMesh, float x, float z, float rad);
	~CMarine();
	void BuildMarine(int x, int z);
	void Approach(IModel* player);	//Move till you get in range or move away if you are too close
	void Aim();
	bool Delete();
	void Fire(IModel* dummyModel, IMesh* bulletMesh, int x, int y, int z, float& frameTime);
	bool ClearBullet(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);
	void TakeDamage(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr);

};
