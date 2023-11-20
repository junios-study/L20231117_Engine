#include "SimpleEngine.h"
#include "Player.h"
#include "World.h"

int main()
{
	SimpleEngine* MyEngine = new SimpleEngine();

	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;
		
	return 0;
}