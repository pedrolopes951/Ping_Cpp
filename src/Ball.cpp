#include "Ball.hpp"

namespace Ball
{
    Ball::Ball(float startX, float startY)
    {
        m_Position.x = startX;
        m_Position.y = startY;

        m_Shape.setSize(sf::Vector2f(10, 10));
        m_Shape.setPosition(m_Position);
    }

    sf::FloatRect Ball::getPosition()
    {
        return m_Shape.getGlobalBounds();
    }

    sf::RectangleShape Ball::getShape()
    {
        return m_Shape;
    }
    float Ball::getXVelocity()
    {
        return m_DirectionX;
    }
    void Ball::reboundSides()
    {
        m_DirectionX = -m_DirectionX;
    }
    void Ball::changeXdir()
    {
        m_DirectionX = -m_DirectionX;
    }

    void Ball::changeYdir()
    {
        m_DirectionY = -m_DirectionY;
    }

    void Ball::reboundTop(int posX, int posY)
    {
        m_Position.y = static_cast<float>(posY);
        m_Position.x = static_cast<float>(posX);
        m_DirectionY = -m_DirectionY;
        resetSpeed();
    }
    void Ball::reboundBat()
    {
        m_DirectionY = -m_DirectionY;
        incrementSpeed();
    }
    void Ball::reboundBatOrTop()
    {
        m_DirectionY = -m_DirectionY;
        incrementSpeed();
    }
    void Ball::reboundBottom(int posX, int posY)
    {
        m_Position.y = static_cast<float>(posY);
        m_Position.x = static_cast<float>(posX);
        m_DirectionY = -m_DirectionY;
        resetSpeed();
    }
    void Ball::incrementSpeed()
    {
        m_incrementSpeed += 200.0f;
    }
    void Ball::resetSpeed()
    {
        m_incrementSpeed = 0.0f;
    }
    float Ball::getSpeed()
    {
        return m_Speed+m_incrementSpeed;
    }
    void Ball::update(sf::Time dt)
    {
        // Update the ball's position
        m_Position.y += m_DirectionY * (m_Speed+m_incrementSpeed) * dt.asSeconds();
        m_Position.x += m_DirectionX * (m_Speed+m_incrementSpeed) * dt.asSeconds();

        // Move the ball

        m_Shape.setPosition(m_Position);
    }
};
