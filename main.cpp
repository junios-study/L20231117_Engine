#include "SimpleEngine.h"
#include "Player.h"
#include "Floor.h"
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct pointer_less_than
{
	const bool operator()(const T* a, const T* b) const {
		// check for 0
		if (a == 0) {
			return b != 0; // if b is also 0, then they are equal, hence a is not < than b
		}
		else if (b == 0) {
			return false;
		}
		else {
			return *a < *b;
		}
	}
};


int main()
{
	vector<AActor*> Actors;
	Actors.push_back(new APlayer(0, 0));
	Actors.push_back(new AFloor(0, 0));
	sort(Actors.begin(), Actors.end(), pointer_less_than<AActor>());

	//vector<AActor> Actors;
	//Actors.push_back(APlayer(0, 0));
	//Actors.push_back(AFloor(0, 0));

	//sort(Actors.begin(), Actors.end());


	//SimpleEngine* MyEngine = new SimpleEngine();

	//MyEngine->LoadLevel("a.smap");
	//MyEngine->Run();

	//delete MyEngine;

	return 0;
}