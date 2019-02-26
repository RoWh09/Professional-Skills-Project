#include "CDroid.h"
#include "Utility.h"

CDroid::CDroid()
{
	health = 2;
	moveSpeed = 8.0f;
	explosionDistance = 2.0f;
	explosionRadius = 4.0f;

	/*MISSING MODEL CREATION - NEEDS POSITION WHERE IT WILL BE SPAWNED*/
}

CDroid::~CDroid()
{
	delete this;
}

void CDroid::Fire(IModel* player, IModel* droid)
{
	if (utility::getDistance(player, droid) =< explosionDistance)	//If close enough to explode, then do so
	{
		/*MISSING - DO DAMAGE TO THE PLAYER IN explosionRadius*/
		/*MISSING - SPAWN PARTICLE SYSTEM*/
		/*MISSING - DELETE IN MAIN*/
	}
}

void CDroid::Approach(IModel* player, IModel* droid)
{
	if (utility::getDistance(player, droid) > explosionDistance)	//If not close enough to explode, then move closer
	{
		droid->LookAt(player);
		droid->MoveLocalZ(moveSpeed);
	}
}
