#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

class CMarine
{
private:
	int health;
	float moveSpeed;
	float fireDistance;		//How far can he start to shoot?
	float fleeDistance;		//Will flee if too close
	IMesh* marineMesh;
	IModel* marineModel;

public:
	CMarine();
	~CMarine();
	void Shoot(IModel*, IModel*);
	void Move(IModel*, IModel*);	//Move till you get in range or move away if you are too close
};