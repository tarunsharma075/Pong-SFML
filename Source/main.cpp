#include"../../Header/GameWindowManager.h"
#include"../../Header/EventManager.h"
using namespace GameManager;
using namespace Event;

int main() {
	GameWindowsManager* gamewindowManager;
	gamewindowManager = new GameWindowsManager();
	EventManager event;

	gamewindowManager->Initialize();

	while(gamewindowManager->isGameRuning()){

		event.PoolEvent(gamewindowManager->getgamewindow());
		event.IsLeftButtonPressed();

		gamewindowManager->render();
	}
	delete(gamewindowManager);
}