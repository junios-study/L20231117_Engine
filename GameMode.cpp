#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "SimpleEngine.h"
#include "World.h"
#include <iostream>
#include "GameState.h"

AGameMode::AGameMode()
{
	SortOrder = 1000;
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick() //Server
{
	AActor::Tick();

	if (SimpleEngine::GetGameState()->IsNextLevel)
	{
		std::cout << "Complete" << std::endl;
		//GEngine->LoadLevel("Data/Level02.smap");
	}

	if (SimpleEngine::GetGameState()->IsGameOver)
	{
		std::cout << "GameOver" << std::endl;
		GEngine->Stop();
	}

}
