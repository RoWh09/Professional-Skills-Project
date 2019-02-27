// Jack2D.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine(kTLX);
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder("C:\\ProgramData\\TL-Engine\\Media");
	/**** Set up your scene here ****/

	bool shootFired = false;
	float playerXPos;
	float playerZpos;
	float mouseXPos;
	float mouseZPos;
	int i = 0;

	//Camera
	ICamera* myCamera = myEngine->CreateCamera();
	/**************************/
	//player
	IMesh* playerMesh = myEngine->LoadMesh("Arrow.x");
	IModel* player = playerMesh->CreateModel();
	/**************************/
	//floor
	IMesh* floorMesh = myEngine->LoadMesh("floor.x");
	IModel* floor = floorMesh->CreateModel();
	/**************************/

	//bulletSpawn
	IMesh* spawnMesh = myEngine->LoadMesh("cube.x");
	IModel* spawnModel = spawnMesh->CreateModel();
	/**************************/

	//Bullet
	IMesh* bulletMesh = myEngine->LoadMesh("cube.x");
	IModel* bulletModel[10];
	/**************************/

	//dummy
	IMesh* dummyMesh = myEngine->LoadMesh("cube.x");
	IModel* dummy = dummyMesh->CreateModel();
	/**************************/
	myCamera->SetLocalY(200);
	myCamera->RotateLocalX(90);
	spawnModel->AttachToParent(player);
	spawnModel->MoveZ(10);

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		/**** Update your scene each frame here ****/
		
		
		playerXPos = player->GetX();
		playerZpos = player->GetX();

		mouseXPos = myEngine->GetMouseMovementX();
		mouseZPos = myEngine->GetMouseMovementY();

		mouseXPos = mouseXPos;
		mouseZPos = -mouseZPos;

		dummy->MoveX(mouseXPos / 3);
		dummy->MoveZ(mouseZPos / 3);
		player->LookAt(dummy);

		myCamera->SetLocalX(player->GetX());
		myCamera->SetLocalZ(player->GetZ());


		if (myEngine->KeyHeld(Key_W))
		{
			player->MoveZ(1);
			dummy->MoveZ(1);
		}
		if (myEngine->KeyHeld(Key_S))
		{
			player->MoveZ(-1);
			dummy->MoveZ(-1);
		}
		if (myEngine->KeyHeld(Key_D))
		{
			player->MoveX(1);
			dummy->MoveX(1);
		}
		if (myEngine->KeyHeld(Key_A))
		{
			player->MoveX(-1);
			dummy->MoveX(-1);
		}

		
		if (myEngine->KeyHit(Key_Q))
		{
			
			bulletModel[i] = bulletMesh->CreateModel(spawnModel->GetX(), spawnModel->GetY(), spawnModel->GetZ());
			bulletModel[i]->LookAt(dummy);
			shootFired = true;
			i++;
		}
		if (shootFired == true)
		{
			for (int j = 0; j <= i-1; ++j)
			{
				bulletModel[j]->MoveLocalZ(1.0);
			}
		}

	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}