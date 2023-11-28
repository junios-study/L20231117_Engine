#include "SimpleEngine.h"

using namespace std;

int main()
{
	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	MyEngine->LoadLevel("Data/level01.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}