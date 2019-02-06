#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

class CDroid
{
private:
	int health;
	float moveSpeed;
	float explosionDistance;	//How far can he start to shoot?
	float explosionRadius;		//Will flee if too close

	IMesh* droidMesh;
	IModel* droidModel;

public:
	CDroid();
	~CDroid();
	void Explode(IModel*, IModel*); //Explode if in range
	void Move(IModel*, IModel*);	//Move till you get in range or move away if you are too close
};