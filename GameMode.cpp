#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "SimpleEngine.h"
#include "World.h"
#include <iostream>

AGameMode::AGameMode()
{
	SortOrder = 0;
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor::Tick();
	APlayer* MyPlayer = nullptr;
	AGoal* MyGoal = nullptr;
	for (auto Actor : GEngine->GetWorld()->GetAllActors())
	{
		APlayer* TempMyPlayer = dynamic_cast<APlayer*>(Actor);
		if (TempMyPlayer)
		{
			MyPlayer = TempMyPlayer;
		}

		AGoal* TempMyGoal = dynamic_cast<AGoal*>(Actor);
		if (TempMyGoal)
		{
			MyGoal = TempMyGoal;
		}
	}

	if (MyPlayer && MyGoal &&
		MyGoal->GetX() == MyPlayer->GetX() &&
		MyGoal->GetY() == MyPlayer->GetY() )
	{
		std::cout << "Complete" << std::endl;
		GEngine->Stop();
	}

}
