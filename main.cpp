#include "SimpleEngine.h"
#include "Player.h"
#include "World.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class NHR
{
public:
	NHR(int NewMoney) { Money = NewMoney; }
	virtual ~NHR() {}

	int Money;

	//연산자 오버로딩
	bool operator>(const NHR& RHS) const
	{
		return this->Money > RHS.Money;
	}

	bool operator<(const NHR& RHS) const
	{
		return this->Money < RHS.Money;
	}
};

bool compare(const NHR& LHS, const NHR& RHS)
{
	if (LHS.Money < RHS.Money)
	{
		return true;
	}
	return false;
}

int main()
{
	vector<NHR> NHRS;

	NHRS.push_back(NHR(20));
	NHRS.push_back(NHR(110));
	NHRS.push_back(NHR(40));
	NHRS.push_back(NHR(50));
	//sort(NHRS.begin(), NHRS.end(), less<NHR>());
	sort(NHRS.begin(), NHRS.end(), [](const NHR& LHS, const NHR& RHS) {
		return LHS.Money < RHS.Money;
		});

	for (const auto& Data : NHRS)
	{
		cout << Data.Money << endl;
	}
	//cout << (NHRS[1] > NHRS[2]) << endl;

	//SimpleEngine* MyEngine = new SimpleEngine();

	//MyEngine->LoadLevel("a.smap");
	//MyEngine->Run();

	//delete MyEngine;
		
	return 0;
}