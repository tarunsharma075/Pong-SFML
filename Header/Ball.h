#pragma once
#include"SFML/Graphics.hpp"
using  namespace sf;
namespace Ball {
	class BallManager {
	private:
		CircleShape ballSprite;
		int radius = 20;;
		const float position_x = 900.0f;
		const float position_y = 530.0f;
	public:
		BallManager();
		void update();

		void render(RenderWindow* gameWindow);

		~BallManager();
};
}