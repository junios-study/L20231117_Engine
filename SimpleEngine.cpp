#include "SimpleEngine.h"
#include "World.h"

//**********
//*P       *
//*        *
//*        *
//*     M  *
//*        *
//*        *
//*        *
//*       G*
//**********

SimpleEngine::SimpleEngine()
{
	IsRunning = true;
}

SimpleEngine::~SimpleEngine()
{
}

void SimpleEngine::Init()
{
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{
		//Input
		//Tick
		//Render
	}
}

void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
}
