#include"../../Header/Ball.h"
namespace Ball {
	
	BallManager::BallManager::BallManager()
	{
		loadTexture();
		initializeVariables();
	}

	void BallManager::BallManager::update()
	{
		move();
	}
	void BallManager::render(RenderWindow* gameWindow)
	{
		gameWindow->draw(ballSprite);
		
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
		ballSprite.setTexture(ballTexture);
		ballSprite.setScale(scale_x, scale_y);
		ballSprite.setPosition(position_x, position_y);

	}

	void BallManager::move()
	{
		ballSprite.move(Velocity);
	}
}
