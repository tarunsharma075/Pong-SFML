#include"../../Header/Ball.h"
namespace Ball {
	void BallManager::updateDelayTime(float delta_time)
	{
		if (currentState == BallState::Idle)
		{
			elapsed_delay_time += delta_time;
			if (elapsed_delay_time >= delay_duration)
			{
				currentState = BallState::Moving;
				elapsed_delay_time = 0.0f;
			}
			else
			{
				return;
			}
		}
	}
	BallManager::BallManager::BallManager()
	{
		loadTexture();
		initializeVariables();
	}

	void BallManager::BallManager::update(PaddleManager* playerOne, PaddleManager* playerTwo, TimeService* timeService)
	{
		move(timeService);
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
		else if (ball_bounds.intersects(player2_bounds) && Velocity.x > 0) {

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
		FloatRect ballBounds = ballSprite.getGlobalBounds();

		if (ballBounds.left < leftBoundary || ballBounds.left + ballBounds.width > rightBoundary) {
			Reset(); 
		}
	}

	void BallManager::Reset()
	{
		ballSprite.setPosition(position_x, position_y);
		Velocity = Vector2f(ballSpeed, ballSpeed);
		currentState = BallState::Idle; 
		elapsed_delay_time = 0.0f;
	}

	void BallManager::onCollision(PaddleManager* playerOne, PaddleManager* playerTwo)
	{
		handelBoundaryCollision();
		handelCollision(playerOne, playerTwo);
		handelOutOfBounds();
	}

	void BallManager::move(TimeService* timeService)
	{
		updateDelayTime(timeService->getDeltaTime());
		if (currentState == BallState::Moving) {
			ballSprite.move(Velocity * timeService->getDeltaTime() * speedMultiplier);
		}


	}
}
