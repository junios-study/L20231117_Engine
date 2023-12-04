#pragma once
#include "SDL.h"

class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	//accessor
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { Y = NewY; }

	virtual bool operator<(const AActor& RHS) const
	{
		return this->SortOrder < RHS.SortOrder;
	}

	virtual bool operator>(const AActor& RHS) const
	{
		return this->SortOrder > RHS.SortOrder;
	}

	SDL_Color Color;

	int SortOrder;
	bool bCollide;

	Uint16 Size;

protected:
	int X;
	int Y;

	char Shape;
};