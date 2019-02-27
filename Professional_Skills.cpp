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


	float playerXPos; //Player positions
	float playerZpos;
	
	float mouseXPos; //Mouse positions
	float mouseZPos;

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
	//dummy
	IMesh* dummyMesh = myEngine->LoadMesh("cube.x");
	IModel* dummy = dummyMesh->CreateModel();
	/**************************/
	myCamera->SetLocalY(200);
	myCamera->RotateLocalX(90);

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		/**** Update your scene each frame here ****/

		playerXPos = player->GetX(); //Get current player position
		playerZpos = player->GetX();

		mouseXPos = myEngine->GetMouseMovementX(); //Get current mouse position
		mouseZPos = myEngine->GetMouseMovementY();

		mouseZPos = -mouseZPos; //Swap direction

		dummy->MoveX(mouseXPos / 3); //Move a dummy where the mouse is and turn towards it
		dummy->MoveZ(mouseZPos / 3);
		player->LookAt(dummy);

		myCamera->SetLocalX(player->GetX()); //The camera is right above the player
		myCamera->SetLocalZ(player->GetZ());
		
		
		//Up, down, right, left movement
		if (myEngine->KeyHeld(Key_W))
		{
			player->MoveZ(0.01);
			dummy->MoveZ(0.01);
		}
		if (myEngine->KeyHeld(Key_S))
		{
			player->MoveZ(-0.01);
			dummy->MoveZ(-0.01);
		}
		if (myEngine->KeyHeld(Key_D))
		{
			player->MoveX(0.01);
			dummy->MoveX(0.01);
		}
		if (myEngine->KeyHeld(Key_A))
		{
			player->MoveX(-0.01);
			dummy->MoveX(-0.01);
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
