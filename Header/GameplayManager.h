#pragma once
#include"../../Header/Ball.h"
#include"../../Header/Paddle.h"
#include"SFML/Graphics.hpp"
#include"../../Header/EventManager.h"
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
		float player1_position_x=5 ;
		float player1_position_y=540;

		float player2_postion_x=1890 ;
		float player2_postion_y=540 ;
		void initialize();
		

	public:
		GamePlayManager(EventManager *manager);
		void Update();
		void render(RenderWindow* gameWindow);
		
	};


}