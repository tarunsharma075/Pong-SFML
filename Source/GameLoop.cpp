#include"../../Header/GameLoop.h"
namespace Core {
	void Core::GameLoop::Initialize()
	{

		
		Window_Game_Manager = new GameWindowsManager();
		Event_Manager = new EventManager();
		gamePlayManager = new GamePlayManager(Event_Manager);
		soundManager = new SoundManager();
		soundManager->PlayBackgroundMusic();
		Window_Game_Manager->Initialize();



	}

	void Core::GameLoop::PoolEvents()
	{
		Event_Manager->PoolEvent(Window_Game_Manager->getgamewindow());

	}

	void Core::GameLoop::Update()
	{
		gamePlayManager->Update();
	}

	bool Core::GameLoop::IsGameRunning()
	{
		return Window_Game_Manager->isGameRuning();
	}

	void Core::GameLoop::Render()
	{
		Window_Game_Manager->clearGameWindow();
		gamePlayManager->render(Window_Game_Manager->getgamewindow());

		Window_Game_Manager->displayGameWindow();
	}
}
