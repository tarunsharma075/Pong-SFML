#include"../../Header/Ball.h"
namespace Ball {
	BallManager::BallManager::BallManager()
	{
		loadTexture();
		initializeVariables();
	}

	void BallManager::BallManager::update()
	{
	}
	void BallManager::render(RenderWindow* gameWindow)
	{
		gameWindow->draw(ball);
		
	}
	BallManager::~BallManager()
	{
	}
	void BallManager::loadTexture()
	{
		if (!ballTexture.loadFromFile(texture_Path)) {

			throw runtime_error("failed to load");
		}
	}
	void BallManager::initializeVariables()
	{
		ball.setTexture(ballTexture);
		ball.setScale(scale_x, scale_y);
		ball.setPosition(position_x, position_y);

	}
}
