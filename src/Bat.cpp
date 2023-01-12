#include "Bat.hpp"

// This the constructor and it is called when we create an object
Bat::Bat::Bat(float startX, float startY) 
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setPosition(m_Position);
}
sf::FloatRect Bat::Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}
sf::RectangleShape Bat::Bat::getShape()
{
    return m_Shape;
}
void Bat::Bat::moveLeft()
{
    m_MovingLeft = true;
}
void Bat::Bat::moveRight()
{
    m_MovingRight = true;
}
void Bat::Bat::stopLeft()
{
    m_MovingLeft = false;
}
void Bat::Bat::stopRight()
{
    m_MovingRight = false;
}
void Bat::Bat::update(sf::Time dt)
{
    if (m_MovingLeft)
    {
        if(m_Position.x > 0)
        {
            m_Position.x -= m_Speed * dt.asSeconds();
        }
        else
        {
            m_Position.x = 0;
        }
    }
    if (m_MovingRight)
    {
        if(m_Position.x < (1920-m_Shape.getSize().x))
        {
            m_Position.x += m_Speed * dt.asSeconds();
        }
        else
        {
            m_Position.x =  (1920-m_Shape.getSize().x);
        }
    }
    m_Shape.setPosition(m_Position);
}
