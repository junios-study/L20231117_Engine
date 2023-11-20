#pragma once
#include <string>

class UWorld;
class AActor;

class SimpleEngine
{
public:
	SimpleEngine();
	virtual ~SimpleEngine();

	void Init();

	void Run();

	void Stop();

	void Term();

	void LoadLevel(std::string Filename);

	inline UWorld* GetWorld() const { return World; };

protected:
	UWorld* World;
	bool IsRunning;

	int Input();
	void Tick(int KeyCode);
	void Render();
};

