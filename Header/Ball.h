#pragma once
#include "SFML/Graphics.hpp"
#include"../../Header/Paddle.h"
#include <iostream>
#include"../../Header/TimeService.h"
#include"../../Header/SoundManager.h"
using namespace Sound;
using namespace Utility;
using namespace std;
using namespace sf;
using namespace Paddle;


namespace Ball {
    enum class BallState
    {
        Idle,
        Moving
    };

    class BallManager {
    private:
        Texture ballTexture;
      

        const float position_x = 880.0f;
        const float position_y = 530.0f;
        Sprite ballSprite;
        string texture_Path = "Assets/Textures/Ball.png";
        const float scale_x = 0.06f;
        const float scale_y = 0.06f;
        const float ballSpeed = 10.f;
        float topBoundary = 20.f;
        float bottomBoundary = 1060.f;
        Vector2f Velocity = Vector2f(ballSpeed, ballSpeed);
        const float leftBoundary = 0.0;
        const float rightBoundary = 1920.f;
        void move(TimeService* timeService);
        float speedMultiplier = 0.f;
        float elapsed_delay_time=0.0f;
        float delay_duration = 2.f;
        void updateDelayTime(float delta_time);
        BallState currentState= BallState::Moving ;
        bool hadLeftCollision = false;
        bool hadRightCollsion = false;
    public:
        BallManager();
        void update(PaddleManager* playerOne, PaddleManager* playerTwo , TimeService* timeService);

        void render(RenderWindow* gameWindow);

        ~BallManager();

        void loadTexture();
        void initializeVariables();

        void handelCollision(PaddleManager* playerOne, PaddleManager* playerTwo);
        void handelBoundaryCollision();
        void handelOutOfBounds();
        void Reset();
        void onCollision(PaddleManager* playerOne, PaddleManager* playerTwo);
        bool isLeftCollisionOccurred();
        void updateLeftCollisionState(bool value);
        bool isRightCollisionOccurred();
        void updateRightCollisionState(bool value);

    };
}
