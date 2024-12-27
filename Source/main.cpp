#include"../../Header/GameWindowManager.h"
using namespace GameManager;

int main() {
	GameWindowsManager* gamewindowManager;
	gamewindowManager = new GameWindowsManager();

	gamewindowManager->Initialize();

	while(gamewindowManager->isGameRuning()){
		gamewindowManager->render();
	}
	delete(gamewindowManager);
}