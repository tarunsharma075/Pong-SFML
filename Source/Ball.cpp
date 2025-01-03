#include"../../Header/Ball.h"
namespace Ball {
	BallManager::BallManager::BallManager()
	{
		ballSprite.setRadius(radius);
		ballSprite.setPosition(position_x, position_y);
	}

	void BallManager::BallManager::update()
	{
	}
	void BallManager::render(RenderWindow* gameWindow)
	{
		gameWindow->draw(ballSprite);
		
	}
	BallManager::~BallManager()
	{
	}
}
