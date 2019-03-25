#include "CMarines.h"
#include "Utility.h"

CMarine::CMarine(IMesh* marineMesh, float x, float z, float rad)	//Constructor
{
	mMesh = marineMesh;
	health = 3;
	moveSpeed = 0.10f;
	fireDistance = 8.0f;
	fleeDistance = 4.0f;
	xPos = x;
	zPos = z;
	mRad = rad;
}

CMarine::~CMarine() {};//Destructor

void CMarine::BuildMarine(int x, int z)
{

	marineModel = mMesh->CreateModel(x, 0.0f, z);
}

void CMarine::Fire(IModel* player, IMesh* bulletMesh, int x, int y, int z, float frameTime)
{
	float speed = 10;
	bool ShotFired = false;
	const float frameTimeFixed = 1.0f / 60;
	float tickDelay = 0.50f;
	ShotFired = Delay(frameTimeFixed, tickDelay);
	if (ShotFired == true)
	{
		bulletPtr.reset(new CRifle(bulletMesh, 1.0));
		bulletPtr->buildBullet(x, y, z);
		bulletPtr->bulletModel->LookAt(player);
		bulletPtr->bulletModel->Scale(0.2);
		bulletList.push_back(move(bulletPtr));
		ShotFired = false;
	}

	auto p = bulletList.begin();
	while (p != bulletList.end())
	{
		(*p)->move(frameTime);
		++p;
	}
	ClearBullet(bulletList, bulletPtr);
}

void CMarine::Approach(IModel* player, float frameTime)
{
	float speed = 50.0f;
	marineModel->LookAt(player);
	marineModel->MoveLocalZ(speed * frameTime);
}

void CMarine::Aim()
{

}

void CMarine::Looking() {};

void CMarine::RemoveBullet()
{
	//mMesh->RemoveModel()
}

bool CMarine::ClearBullet(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
	auto p = bulletList.begin();//pointer to beggining of the que 
	while (p != bulletList.end())
	{
		//collision detection with the perimiter wanted
		bool BulletOutRange = (*p)->getDistance(marineModel->GetX(), marineModel->GetZ(), 200.0f, (*p)->bulletModel->GetX(), (*p)->bulletModel->GetZ(), 2.0f);

		if (BulletOutRange == false)
		{
			(*p)->Delete();
			bulletList.erase(p);
			break;//quits the while loop if collision is detected
		}
		p++;
	}
	return true;
}

void CMarine::TakeDamage(deque <unique_ptr < CRifle > >& bulletList, unique_ptr<CRifle>&bulletPtr)
{
	auto p = bulletList.begin();
	while (p != bulletList.end())
	{
		bool bulletHit = utility::getDistance(marineModel->GetX(), marineModel->GetZ(), 5.0f, (*p)->bulletModel->GetX(), (*p)->bulletModel->GetZ(), 2.0f);
		if (bulletHit == true)
		{
			(*p)->Delete();
			bulletList.erase(p);
			--health;
			break;//quits the while loop if collision is detected
		}
		p++;
	}
}

bool  CMarine::Delete()
{

	if (health <= 0)
	{
		if (!bulletList.empty())
		{
			bool finished = false;
			while (finished == false)
			{
				auto p = bulletList.begin();
				
				if (p == bulletList.end())
				{
					finished = true;
				}
				else
				{
					(*p)->Delete();
					bulletList.erase(p);
				}
				
				
			}
		}
		
		mMesh->RemoveModel(marineModel);
		return true;
		
	}


}

bool CMarine::Delay(const float frameTimeFixed, float tickDelay)
{
	static float counterFrame = 0.0f;

	counterFrame += frameTimeFixed;

	if (counterFrame > tickDelay)
	{
		counterFrame = 0;
		return true;
	}
	return false;
}

/*MISSING - NEEDS TO BE DELETED IN THE MAIN IF HEALTH GOES BELOW ZERO*/