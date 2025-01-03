#include"../../Header/GameplayManager.h"
namespace GamePlay {
	
	GamePlayManager::GamePlayManager(EventManager* manager)
	{
		eventManager = manager;
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
		ball->update();

		paddlePlayer1->Update(eventManager->IskeyPressed(Keyboard::W),
			eventManager->IskeyPressed(Keyboard::S));
		paddlePlayer2->Update(eventManager->IskeyPressed(Keyboard::Up),
			eventManager->IskeyPressed(Keyboard::Down));
	}
	void GamePlayManager::render(RenderWindow* gameWindow)
	{
		ball->render(gameWindow);
		paddlePlayer1->render(gameWindow);
		paddlePlayer2->render(gameWindow);

	}
	
}