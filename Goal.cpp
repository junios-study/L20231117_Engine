#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	X = 10;
	Y = 10;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	Shape = NewShape;
	X = NewX;
	Y = NewY;
}

AGoal::~AGoal()
{
}
