#pragma once
#include"SFML/Graphics.hpp"
#include"../../Header/Paddle.h"
#include"../Header/TimeService.h"
using namespace sf;
using namespace Utility;
namespace Paddle {
	class PaddleManager {

	private:
		RectangleShape paddleSprite;
		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;
		const float paddleSpeed = 10.f;
		float topBoundary = 20.f;
		float bottomBoundary = 1060.f;
		float speedMultiplier = 100.f;
	public:
		PaddleManager(float position_X, float position_Y);
		void Update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* timeSrvice);
		void render(RenderWindow* gameWindow);
		void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed,TimeService *timeSrvice);
		RectangleShape getPaddleSprite();
		void reset(float positionX, float positionY);
	};
}