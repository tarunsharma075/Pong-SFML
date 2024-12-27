#include"../../Header/GameWindowManager.h"
namespace GameManager {
	void GameWindowsManager::GameWindowsManager::Initialize()
	{
		gameWindow = new RenderWindow();
		createGamewindows();
	}
	
	void GameWindowsManager::render()
	{
	}
	RenderWindow* GameWindowsManager::getgamewindow()
	{
		return gameWindow;
	}

	bool GameWindowsManager::isGameRuning()
	{
		return gameWindow->isOpen();
	}

	void GameWindowsManager::createGamewindows()
	{
		gameWindow->create(VideoMode(width, height), gameTile);
	}



}
