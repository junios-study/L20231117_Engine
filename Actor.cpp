#include "Actor.h"
#include <windows.h>
#include <iostream>
#include "SimpleEngine.h"

AActor::AActor() :
	X(0), Y(0), Shape(' '), SortOrder(0), bCollide(false), Size(32)
{

	//X = 0;
	//Y = 0;
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	Size = 32;
}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//현재 액터 위치에 모양 출력
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape ;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	SDL_RenderFillRect(GEngine->MyRenderer, 
		new SDL_Rect{ X * Size, Y * Size, Size, Size });
	
}
