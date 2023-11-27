#pragma once
#include <string>

class UWorld;
class AActor; 
class AGameMode;
class AGameState;

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

	static AGameState* GetGameState()
	{
		return GetInstance()->GameState;
	}

	static AGameMode* GetGameMode()
	{
		return GetInstance()->GameMode;
	}

protected:
	UWorld* World;
	bool IsRunning;

	void Input();
	void Tick();
	void Render();

	static SimpleEngine* Instance;

	AGameMode* GameMode;
	AGameState* GameState;
};

#define GEngine SimpleEngine::GetInstance()


