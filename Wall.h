#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:
	AWall();
	AWall(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100, SDL_Color NewColor = SDL_Color {255, 102, 255, 0});
	virtual ~AWall();
};

