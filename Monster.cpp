#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';
	X = 10;
	Y = 10;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
}

AMonster::~AMonster()
{
}
