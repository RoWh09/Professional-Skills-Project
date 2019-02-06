#include "CMarines.h"
#include "Utility.h"

CMarine::CMarine()	//Constructor
{
	health = 3;
	moveSpeed = 5.0f;
	fireDistance = 8.0f;
	fleeDistance = 4.0f;

	/*MISSING MODEL CREATION - NEEDS POSITION WHERE IT WILL BE SPAWNED*/
}

CMarine::~CMarine()	//Destructor
{
	delete this;
}

void CMarine::Shoot(IModel* player, IModel* marine)
{
	if (utility::getDistance(player, marine) < fireDistance)	//If you are close enough to shoot then do shoot
	{
		/*MISSING - SPAWN PARTICLE SYSTEM*/
		/*MISSING - DEAL DAMAGE TO THE PLAYER*/
	}
	else
	{
		return;
	}
}

void CMarine::Move(IModel* player, IModel* marine)
{
	while (utility::getDistance(player, marine) > fireDistance)		//Get in firing range
	{
		marine->LookAt(player);
		marine->MoveLocalZ(moveSpeed * utility::frameTime);
	}

	while (utility::getDistance(player, marine) < fleeDistance)		//Move back if you are too close
	{
		marine->LookAt(player);
		marine->MoveLocalZ(-moveSpeed * utility::frameTime);
	}
}

/*MISSING - NEEDS TO BE DELETED IN THE MAIN IF HEALTH GOES BELOW ZERO*/