#include "SimpleEngine.h"

int main()
{
	SimpleEngine* MyEngine = new SimpleEngine();

	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}