#include"../../Header/Ball.h"
namespace Ball {
	
	BallManager::BallManager::BallManager()
	{
		loadTexture();
		initializeVariables();
	}

	void BallManager::BallManager::update(PaddleManager* playerOne, PaddleManager* playerTwo)
	{
		move();
		onCollision(playerOne, playerTwo);
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

	void BallManager::handelCollision(PaddleManager* playerOne, PaddleManager* playerTwo)
	{
		const RectangleShape& player1Paddle = playerOne->getPaddleSprite();
		const RectangleShape& player2Paddle = playerTwo->getPaddleSprite();

		FloatRect ball_bounds = ballSprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(player1_bounds) && Velocity.x < 0) {
			Velocity.x = -Velocity.x;
		}
		else if (ball_bounds.intersects(player2_bounds) && Velocity.x> 0) {

			Velocity.x = -Velocity.x;
		}

	}

	void BallManager::handelBoundaryCollision()
	{
		FloatRect ballBounds = ballSprite.getGlobalBounds();

		if (ballBounds.top <= topBoundary && Velocity.y < 0 
			|| ballBounds.top + ballBounds.height >= bottomBoundary && Velocity.y>0) {
			Velocity.y = -Velocity.y;

		}
	}

	void BallManager::handelOutOfBounds()
	{
		FloatRect ballBounds= ballSprite.getGlobalBounds();

		if (ballBounds.left < leftBoundary) {
			Reset();
		}
		else if (ballBounds.left + ballBounds.width > rightBoundary) {
			Reset();
		}
	}

	void BallManager::Reset()
	{
		ballSprite.setPosition(position_x, position_y);
		Velocity = Vector2f(ballSpeed, ballSpeed);
	}

	void BallManager::onCollision(PaddleManager* playerOne, PaddleManager* playerTwo)
	{
		handelBoundaryCollision();
		handelCollision(playerOne, playerTwo);
		handelOutOfBounds();
	}

	void BallManager::move()
	{
		ballSprite.move(Velocity);
	}

	
}
