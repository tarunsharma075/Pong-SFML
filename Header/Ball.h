#pragma once
#include "SFML/Graphics.hpp"
#include"../../Header/Paddle.h"
#include <iostream>
using namespace std;
using namespace sf;
using namespace Paddle;

namespace Ball {
    class BallManager {
    private:
        Texture ballTexture;
      

        const float position_x = 900.0f;
        const float position_y = 530.0f;
        Sprite ballSprite;
        string texture_Path = "Assets/Textures/Ball.png";
        const float scale_x = 0.06f;
        const float scale_y = 0.06f;
        const float ballSpeed = 0.5f;
        float topBoundary = 20.f;
        float bottomBoundary = 1060.f;
        Vector2f Velocity = Vector2f(ballSpeed, ballSpeed);
        const float leftBoundary = 0.0;
        const float rightBoundary = 1920.f;
        void move();

    public:
        BallManager();
        void update(PaddleManager* playerOne, PaddleManager* playerTwo);

        void render(RenderWindow* gameWindow);

        ~BallManager();

        void loadTexture();
        void initializeVariables();

        void handelCollision(PaddleManager* playerOne, PaddleManager* playerTwo);
        void handelBoundaryCollision();
        void handelOutOfBounds();
        void Reset();
        void onCollision(PaddleManager* playerOne, PaddleManager* playerTwo);
    };
}
