#pragma once
#include <string>

class UWorld;
class AActor;

class SimpleEngine
{
private:
	SimpleEngine();

public:
	virtual ~SimpleEngine();

	void Init();

	void Run();

	void Stop();

	void Term();

	void LoadLevel(std::string Filename);

	inline UWorld* GetWorld() const { return World; };

	static SimpleEngine* GetInstance()
	{ 
		if (Instance == nullptr)
		{
			Instance = new SimpleEngine();
		}
		return Instance;
	}

	static int KeyCode;

protected:
	UWorld* World;
	bool IsRunning;

	void Input();
	void Tick();
	void Render();

	static SimpleEngine* Instance;
};

#define GEngine SimpleEngine::GetInstance()


