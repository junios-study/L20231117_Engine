#include "SimpleEngine.h"
#include "World.h"
#include <conio.h>
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"
#include "GameMode.h"
#include "GameState.h"

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

SimpleEngine* SimpleEngine::Instance = nullptr;
int SimpleEngine::KeyCode = 0;


SimpleEngine::SimpleEngine()
{
	GameMode = nullptr;
	GameState = nullptr;
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
		Input();
		Tick();
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
	GameMode = nullptr;
	GameState = nullptr;
	IsRunning = false;
	delete World;
}

void SimpleEngine::LoadLevel(std::string Filename)
{
	//Save
	//Memory -> Disk : Serialize , Text(JSON, csv), binary(umap)

	//Load
	//Disk -> Memory : Deserialize


	//file 바꾸자, 틀이 바꿔 줄꺼임
	std::string Map[10] = {
	//char Map[10][11] = {
		"********************",
		"*P                 *",
		"*                  *",
		"*        M         *",
		"*   M              *",
		"*                  *",
		"*                  *",
		"*                  *",
		"*            G     *",
		"********************"
	};

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < Map[Y].length(); ++X)
		{
			if (Map[Y][X] == '*')
			{
				//Wall
				GetWorld()->SpawnActor(new AWall(X, Y));
			}
			else if (Map[Y][X] == 'P')
			{
				//Player
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Map[Y][X] == 'M')
			{
				//Monster
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Map[Y][X] == 'G')
			{
				//Goal
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
			else if (Map[Y][X] == ' ')
			{
				//Floor
			}
			//Floor
			GetWorld()->SpawnActor(new AFloor(X, Y));
		}
	}

	GetWorld()->SortRenderOrder();

	GameMode = new AGameMode();
	GetWorld()->SpawnActor(GameMode);
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameState);
}

void SimpleEngine::Input()
{
	KeyCode = _getch();
}

void SimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

