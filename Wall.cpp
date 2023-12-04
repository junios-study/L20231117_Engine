#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	SortOrder = 100;
	bCollide = true;
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	bCollide = true;
	Color = NewColor;
	LoadBMP("Data/Wall.bmp");

}

AWall::~AWall()
{
}
