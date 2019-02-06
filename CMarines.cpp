#include "CMarines.h"
#include "Utility.h"

CMarine::CMarine()	//Constructor
{
	health = 3;
	moveSpeed = 5.0f;
	fireDistance = 8.0f;
}

CMarine::~CMarine()	//Destructor
{
	delete this;
}

void CMarine::Shoot(IModel* player, IModel* marine)
{
	if (utility::getDistance(player, marine) < fireDistance)	//If you are close enough to shoot then do shoot
	{
		//Start shooting
	}
	else
	{
		Move(player, marine);
	}
}

void CMarine::Move(IModel* player, IModel* marine)
{
	while ()
	{

	}
	marine->LookAt(player);
	marine->MoveLocalZ(moveSpeed);
}