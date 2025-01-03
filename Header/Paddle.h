#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
namespace Paddle {
	class PaddleManager {

	private:
		RectangleShape paddleSprite;
		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;
		const float paddleSpeed = 0.5;
	public:
		PaddleManager(float position_X, float position_Y);
		void Update(bool move_up_key_pressed, bool move_down_key_pressed);
		void render(RenderWindow* gameWindow);
		void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed);
	};
}