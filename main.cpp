#include "SimpleEngine.h"

using namespace std;

int SDL_main(int argc, char* argv[])
{
	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	MyEngine->LoadLevel("Data/level01.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}