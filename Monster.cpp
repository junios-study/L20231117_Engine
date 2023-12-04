#include "Monster.h"
#include "SimpleEngine.h"
#include "World.h"
#include "Player.h"
#include <iostream>
#include "GameState.h"
#include "GameMode.h"

AMonster::AMonster()
{
	Shape = 'M';
	X = 10;
	Y = 10;
	SortOrder = 300;
	bCollide = false;
	srand((unsigned int)time(nullptr));
	ProcessTime = 500;
	ElaspedTime = 0;
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	Color = NewColor;

	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBMP("Data/Slime.bmp");


}

AMonster::~AMonster()
{
}


void AMonster::Tick()
{
	__super::Tick();

	ElaspedTime += GEngine->GetWorldDeltaSeconds();
	if (ElaspedTime <= ProcessTime)
	{
		return;
	}
	else
	{
		ElaspedTime = 0;
	}

	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		APlayer* MyPlayer = dynamic_cast<APlayer*>(Actor);
		if (MyPlayer &&
			MyPlayer->GetX() == X &&
			MyPlayer->GetY() == Y)
		{
			SimpleEngine::GetGameState()->IsGameOver = true;
			return;
		}
	}

	//random 4 direction, up, down, left, right

	int Direction = rand() % 4;	
	if (Direction == (int)EMonsterDirection::Left)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (Direction == (int)EMonsterDirection::Right)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (Direction == (int)EMonsterDirection::Up)
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (Direction == (int)EMonsterDirection::Down)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
}

bool AMonster::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->bCollide == true &&
			Actor->GetX() == NewX &&
			Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}
