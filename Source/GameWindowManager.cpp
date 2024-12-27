#include"../../Header/GameWindowManager.h"

namespace GameManager {
	void GameWindowsManager::GameWindowsManager::Initialize()
	{
		gameWindow = new RenderWindow();
		createGamewindows();
	}
	
	void GameWindowsManager::render()
	{
		gameWindow->clear(Color(0, 0, 0,255));

		gameWindow->display();
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
		gameWindow->create(VideoMode::getDesktopMode(),gameTile,Style::Default);
	}



}