#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include "EnemiesInterface.h"
using namespace tle;

class CSpaceShip : IEnemies
{
private:
	float moveSpeed = 6.0f;
	IMesh* spaceShipMesh;
	IModel* spaceShipModel;

public:
	CSpaceShip();
	~CSpaceShip();
	void Approach(IModel*); //Move till you get in range or move away if you are too close
	void Aim(IModel*);
	void Fire(IModel*, IModel*); //Explode if in range
	void Reload();
};