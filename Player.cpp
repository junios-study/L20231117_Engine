#include "Player.h"
#include "SimpleEngine.h"
#include "World.h"
#include "Goal.h"
#include "GameState.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
	SpriteIndex = 0;
	SpriteDirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	Color = NewColor;
	LoadBMP("Data/Player.bmp", SDL_Color{ 255, 0, 255, 0 });
	bIsSprite = true;
	SpriteSizeX = 5;
	SpriteSizeY = 5;
	SpriteIndex = 0;
	SpriteDirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();

	ElaspedTime += GEngine->GetWorldDeltaSeconds();
	if (ElaspedTime >= ProcessTime)
	{
		SpriteIndex++;
		SpriteIndex = SpriteIndex % SpriteSizeX;
		ElaspedTime = 0;
	}


	int KeyCode = GEngine->MyEvent.key.keysym.sym;

	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		return;
	}


	if (SimpleEngine::GetGameState()->IsGameOver)
	{
		return;
	}

	if (KeyCode == SDLK_a)
	{
		if (!IsCollide(X - 1, Y))
		{
			SpriteDirection = 0;
			X--;
		}
	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{
			SpriteDirection = 1;
			X++;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{
			SpriteDirection = 2;
			Y--;
		}
	}
	if (KeyCode == SDLK_s)
	{
		if (!IsCollide(X, Y + 1))
		{
			SpriteDirection = 3;
			Y++;
		}
	}
	if (KeyCode == SDLK_ESCAPE)
	{
		GEngine->Stop();
	}

	AGoal* MyGoal = nullptr;
	for (auto Actor : GEngine->GetWorld()->GetAllActors())
	{
		MyGoal = dynamic_cast<AGoal*>(Actor);
		if (MyGoal &&
			MyGoal->GetX() == X &&
			MyGoal->GetY() == Y)
		{
			SimpleEngine::GetGameState()->IsNextLevel = true;
			break;
		}
	}

}

void APlayer::Render()
{
	__super::Render();

	int SpriteWidth = MySurface->w / SpriteSizeX;
	int SpriteHeight = MySurface->h / SpriteSizeY;
	int StartX = SpriteIndex * SpriteWidth;
	int StartY = SpriteDirection * SpriteHeight;

	SDL_RenderCopy(GEngine->MyRenderer,
		MyTexture,
		new SDL_Rect{ StartX, StartY, SpriteWidth, SpriteHeight },
		new SDL_Rect{ X * Size, Y * Size, Size, Size });
}

bool APlayer::IsCollide(int NewX, int NewY)
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
