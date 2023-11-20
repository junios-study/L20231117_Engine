#include "Player.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
}

APlayer::APlayer(int NewX, int NewY)
{
	Shape = 'P';
	SetX(NewX);
	SetY(NewY);
}

APlayer::~APlayer()
{
}

void APlayer::Tick(int KeyCode)
{
//	AActor::Tick(KeyCode);
	__super::Tick(KeyCode);

	if (KeyCode == 'A' || KeyCode == 'a')
	{
		X--;
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		X++;
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		Y--;
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		Y++;
	}
}
