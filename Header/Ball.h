#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;

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

        Vector2f Velocity = Vector2f(ballSpeed, ballSpeed);

        void move();

    public:
        BallManager();
        void update();

        void render(RenderWindow* gameWindow);

        ~BallManager();

        void loadTexture();
        void initializeVariables();
    };
}
