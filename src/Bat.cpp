#include "Bat.hpp"

// This the constructor and it is called when we create an object
BatClass::Bat::Bat(float startX, float startY) 
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setPosition(m_Position);
}
sf::FloatRect BatClass::Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}
sf::RectangleShape BatClass::Bat::getShape()
{
    return m_Shape;
}
void BatClass::Bat::moveLeft()
{
    m_MovingLeft = true;
}
void BatClass::Bat::moveRight()
{
    m_MovingRight = true;
}
void BatClass::Bat::stopLeft()
{
    m_MovingLeft = false;
}
void BatClass::Bat::stopRight()
{
    m_MovingRight = false;
}
void BatClass::Bat::update(sf::Time dt)
{
    if (m_MovingLeft)
    {
        if(m_Position.x > -20)
        {
            m_Position.x -= m_Speed * dt.asSeconds();
        }
        else
        {
            m_Position.x = 1920 / 2;
        }
    }
    if (m_MovingRight)
    {
        if(m_Position.x < 1940)
        {
            m_Position.x += m_Speed * dt.asSeconds();
        }
        else
        {
            m_Position.x =  1920 / 2;
        }
    }
    m_Shape.setPosition(m_Position);
}
