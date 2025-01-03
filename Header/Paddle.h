#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
namespace Paddle {
	class PaddleManager {

	private:
		RectangleShape paddleSprite;
		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;
	public:
		PaddleManager(float position_X, float position_Y);
		void Update();
		void render(RenderWindow* gameWindow);
	};
}