#include"../../Header/GameplayManager.h"
namespace GamePlay {
	
	GamePlayManager::GamePlayManager(EventManager* manager)
	{
		timeService = new TimeService();
		timeService->initialize();
		eventManager = manager;
		boundaryManager = new BoundaryManager();
		uiService = new UIService();
		initialize();
	}
	void GamePlayManager::initialize()
	{
		ball = new BallManager();
		paddlePlayer1 = new PaddleManager(player1_position_x, player1_position_y);
		paddlePlayer2= new PaddleManager(player2_postion_x,player2_postion_y);
	}
	void GamePlayManager::Update()
	{
		timeService->update();
		ball->update(paddlePlayer1,paddlePlayer2, timeService);

		paddlePlayer1->Update(eventManager->IskeyPressed(Keyboard::W),
			eventManager->IskeyPressed(Keyboard::S),timeService);
		paddlePlayer2->Update(eventManager->IskeyPressed(Keyboard::Up),
			eventManager->IskeyPressed(Keyboard::Down), timeService);
		
	}
	void GamePlayManager::render(RenderWindow* gameWindow)
	{
		boundaryManager->Render(gameWindow);
		ball->render(gameWindow);
		paddlePlayer1->render(gameWindow);
		paddlePlayer2->render(gameWindow);
		uiService->Render(gameWindow);

	}
	
}