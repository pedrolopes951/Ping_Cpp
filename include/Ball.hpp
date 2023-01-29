#pragma once
#include "SFML/Graphics.hpp"

namespace Ball
{
    class Ball
    {
    private:
        sf::Vector2f m_Position;
        sf::RectangleShape m_Shape;

        float m_Speed = 500.0f;
        float m_DirectionX = .2f;
        float m_DirectionY = .2f;
        float m_incrementSpeed = 0.0f;
        

    public:
        Ball(float startX, float startY);
        float getSpeed();
        sf::FloatRect getPosition();
        sf::RectangleShape getShape();
        float getXVelocity();
        void reboundSides();
        void reboundTop(int posX = 500, int posY = 0);
        void reboundBat();
        void reboundBatOrTop(); 
        void reboundBottom(int posX = 500, int posY = 0);
        void changeYdir();
        void changeXdir();
        void incrementSpeed();
        void resetSpeed();
        void update(sf::Time dt);
        ~Ball(){};
    };
};