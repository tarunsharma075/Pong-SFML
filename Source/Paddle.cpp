#include"../../Header/Paddle.h"
namespace Paddle {
	PaddleManager::PaddleManager(float position_X, float position_Y)
	{
		paddleSprite.setSize(Vector2f(paddle_width, paddle_height));
		paddleSprite.setPosition(position_X,position_Y);
	}
	void PaddleManager::Update()
	{
	}
	void PaddleManager::render(RenderWindow* gameWindow)
	{
		gameWindow->draw(paddleSprite);
	}
}

