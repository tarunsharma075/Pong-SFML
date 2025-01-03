#include"../../Header/GameplayManager.h"
namespace GamePlay {
	
	GamePlayManager::GamePlayManager()
	{
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
	}
	void GamePlayManager::render(RenderWindow* gameWindow)
	{
		ball->render(gameWindow);
		paddlePlayer1->render(gameWindow);
		paddlePlayer2->render(gameWindow);

	}
	
}