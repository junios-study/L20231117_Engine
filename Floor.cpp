#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 1;
}

AFloor::AFloor(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	Color = NewColor;
	LoadBMP("Data/floor.bmp");

}

AFloor::~AFloor()
{
}
