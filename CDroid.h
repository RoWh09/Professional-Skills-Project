#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include "EnemiesInterface.h"
using namespace tle;

class CDroid : IEnemies
{
private:
	int health = 2;
	float moveSpeed = 8.0f;
	float explosionDistance = 2.0f;	//How far can he start to shoot?
	float explosionRadius = 4.0f;		//Will flee if too close

	IMesh* droidMesh;
	IModel* droidModel;

public:
	CDroid();
	~CDroid();
	void Approach(IModel*, IModel*); //Move till you get in range or move away if you are too close
	void Aim(IModel*, IModel*);
	void Fire(IModel*, IModel*); //Explode if in range
	void Reload();
};
