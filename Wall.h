#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:
	AWall();
	AWall(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100);
	virtual ~AWall();
};

