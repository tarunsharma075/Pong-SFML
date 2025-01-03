#pragma once
#include"SFML/Graphics.hpp"
#include"../../Header/GameWindowManager.h"
#include"../../Header/EventManager.h"
#include"../../Header/GameplayManager.h"
using namespace sf;
using namespace Event;
using namespace GameManager;
using namespace GamePlay;
namespace Core {
	class GameLoop {
	private:
		GameWindowsManager* Window_Game_Manager;
		EventManager* Event_Manager;
		GamePlayManager* gamePlayManager;
		
	public:
		void Initialize();
		void PoolEvents();
		void Update();
		bool IsGameRunning();
		void Render();
	
	};
}