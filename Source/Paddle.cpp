#include"../../Header/Paddle.h"
namespace Paddle {
	PaddleManager::PaddleManager(float position_X, float position_Y)
	{
		paddleSprite.setSize(Vector2f(paddle_width, paddle_height));
		paddleSprite.setPosition(position_X,position_Y);
	}
	void PaddleManager::Update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* timeSrvice)
	{

		movePaddle( move_up_key_pressed,  move_down_key_pressed, timeSrvice);
	}
	void PaddleManager::render(RenderWindow* gameWindow)
	{
		gameWindow->draw(paddleSprite);
	}
	void PaddleManager::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed , TimeService* timeSrvice)
	{
		if (move_up_key_pressed && paddleSprite.getPosition().y>topBoundary) {
			paddleSprite.move(0, -paddleSpeed * timeSrvice->getDeltaTime()*speedMultiplier);
		}
		else if (move_down_key_pressed && paddleSprite.getPosition().y + paddleSprite.getSize().y <bottomBoundary) {
			paddleSprite.move(0, paddleSpeed * timeSrvice->getDeltaTime() * speedMultiplier);
		}
	}
	RectangleShape PaddleManager::getPaddleSprite()
	{
		return paddleSprite;
	}
	void PaddleManager::reset(float positionX, float positionY)
	{
	}
}

