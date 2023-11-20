#include "SimpleEngine.h"
#include "World.h"
#include <conio.h>
#include "Player.h"
#include "Wall.h"

//**********
//*P       *
//*        *
//*        *
//*     M  *
//*        *
//*        *
//*        *
//*       G*
//**********

SimpleEngine::SimpleEngine()
{
	Init();
}

SimpleEngine::~SimpleEngine()
{
	Term();
}

void SimpleEngine::Init()
{
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{
		int KeyCode = Input();
		Tick(KeyCode);
		//Clear Screen
		system("cls");
		Render();
	}
}

void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
	IsRunning = false;
	delete World;
}

void SimpleEngine::LoadLevel(std::string Filename)
{
	//Save
	//Memory -> Disk : Serialize , Text(JSON, csv), binary(umap)

	//Load
	//Disk -> Memory : Deserialize
	GetWorld()->SpawnActor(new APlayer(10, 10));
	GetWorld()->SpawnActor(new AWall(0, 0));
	GetWorld()->SpawnActor(new AWall(1, 0));
	GetWorld()->SpawnActor(new AWall(0, 1));
}

int SimpleEngine::Input()
{
	int KeyCode = _getch();

	return KeyCode;
}

void SimpleEngine::Tick(int KeyCode)
{
	GetWorld()->Tick(KeyCode);
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

