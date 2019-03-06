// MiainGame.cpp: A program using the TL-Engine

#include "CMarines.h"
#include "Weapons.h"
#include "Player.h"
#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );

	/**** Set up your scene here ****/
	float playerXPos;
	float playerZpos;
	float mouseXPos;
	float mouseZPos;

	float frameTime;
	float time = 0;
	int i = 0;

	string meshName = "Cube.x";

	ICamera* myCamera = myEngine->CreateCamera(kManual, 0.0f, 0.0f, 0.0f);

	IMesh* floorMesh = myEngine->LoadMesh("Floor.x");
	IModel* floor = floorMesh->CreateModel();

	IMesh* bulletMesh = myEngine->LoadMesh("Sphere.x");

	IMesh* marineMesh = myEngine->LoadMesh("Sphere.x");

	IMesh*	playerMesh = myEngine->LoadMesh("Cube.x");
	
	IMesh*	dummyMesh = myEngine->LoadMesh("Sphere.x");
	IModel*	dummyModel = dummyMesh->CreateModel(0.0f, 5.0f, 0.0f);
	dummyModel->SetSkin("Blue.png");
	dummyModel->Scale(.2);
	
	ISprite* Ham = myEngine->CreateSprite("ham.png", 0.0f, .0f, .0f);
	ISprite* HamOne = myEngine->CreateSprite("ham.png", 100.0f, .0f, .0f);
	ISprite* hamTwo = myEngine->CreateSprite("ham.png", 200.0f, .0f, .0f);

	deque <unique_ptr < CRifle > > bulletList;
	unique_ptr<CRifle>bulletPtr;
	
	deque <unique_ptr < CMarine > > marineList;
	unique_ptr<CMarine>marinePtr;

	CPlayer currentPlayer(playerMesh, myEngine, "PlayerOne", 100, 100);
	dummyModel->AttachToParent(currentPlayer.playerModel);
	myCamera->AttachToParent(currentPlayer.playerModel);
	myCamera->MoveLocalY(200.0f);
	myCamera->RotateLocalX(90);
	CMarine currentMarine(marineMesh, 20, 20, 5);
	currentPlayer.playerModel->SetSkin("ham.png");
	currentPlayer.playerModel->Scale(2);
	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		/**** Update your scene each frame here ****/
		

		frameTime = myEngine->Timer();
		time += frameTime;
		playerXPos = currentPlayer.playerModel->GetX();
		playerZpos = currentPlayer.playerModel->GetX();

		mouseXPos = myEngine->GetMouseMovementX();
		mouseZPos = myEngine->GetMouseMovementY();

		mouseXPos = mouseXPos;
		mouseZPos = -mouseZPos;

		dummyModel->MoveX(mouseXPos / 3);
		dummyModel->MoveZ(mouseZPos / 3);

		currentPlayer.Move();

		if (myEngine->KeyHit(Mouse_LButton))
		{
			currentPlayer.Shoot(dummyModel, bulletMesh, bulletList, bulletPtr, currentPlayer.playerModel->GetX(), currentPlayer.playerModel->GetY(), currentPlayer.playerModel->GetZ());
		}

		auto p = bulletList.begin();
		while (p != bulletList.end())
		{
			(*p)->move(10.0);
			(*p)->bulletModel->RotateLocalZ(90);
			++p;
		}
		

		currentPlayer.ClearBullet(dummyModel, bulletList, bulletPtr);

		if (myEngine->KeyHit(Key_F))
		{
			marinePtr.reset(new CMarine(marineMesh, 20, 20, 2));
			marinePtr->BuildMarine(20, 20);
			marineList.push_back(move(marinePtr));
		}

		
		auto j = marineList.begin();
		while (j != marineList.end())
		{
			(*j)->Fire(currentPlayer.playerModel, bulletMesh, (*j)->marineModel->GetX(), 0, (*j)->marineModel->GetZ(), time);
			(*j)->Approach(currentPlayer.playerModel);
			(*j)->TakeDamage(bulletList, bulletPtr);
			bool deleteMarine = (*j)->Delete();
			if (deleteMarine == true)
			{
				marineList.erase(j);
				break;
			}
			++j;
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

