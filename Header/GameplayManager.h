#pragma once
#include"../../Header/Ball.h"
#include"../../Header/Paddle.h"
#include"SFML/Graphics.hpp"
#include"../../Header/EventManager.h"
#include"../../Header/Boundary.h"
#include"../../Header/TimeService.h"
using namespace Utility;
using namespace Boundary;
using namespace Paddle;
using namespace Ball;
using namespace sf;
using namespace Event;
namespace GamePlay {
	class GamePlayManager {

		BallManager* ball;
		PaddleManager* paddlePlayer1;
		PaddleManager* paddlePlayer2;
		EventManager* eventManager;
		float player1_position_x=26.f ;
		float player1_position_y=540;

		float player2_postion_x=1870 ;
		float player2_postion_y=540 ;
		void initialize();
		BoundaryManager* boundaryManager;
		TimeService* timeService;

	public:
		GamePlayManager(EventManager *manager);
		void Update();
		void render(RenderWindow* gameWindow);
		
	};


}