#include "SimpleEngine.h"


int main()
{
	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}