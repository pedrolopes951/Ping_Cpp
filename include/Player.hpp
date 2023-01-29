#pragma once
#include "StructGame.hpp"
#include "Bat.hpp"
#include "Ball.hpp"
#include "GameLibrary.hpp"
#include <sstream>

class Player
{

private:
public:
    virtual void update(ClockGame::MyClock &clock, sf::RenderWindow &window) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual ~Player(){};
};

class SinglePlayer : public Player
{

private:
    struct Scores_SinglePlayer
    /*
        Struct to hold the game score and the life of the player
    */
    {
        int m_score;
        int m_lives;
        void reset()
        {
            m_score = 0;
            m_lives = 3;
        }
    };
    Scores_SinglePlayer score{0, 3};
    Bat::Bat m_bat;
    Ball::Ball m_ball;
    TextGame::MyText m_hud;

public:
    SinglePlayer() : m_bat(1920 / 2, 1080 - 20), m_ball(1920 / 2, 0), m_hud("fonts/DS-DIGI.TTF", 75, sf::Color::White, 20, 20)
    {
    }
    void update(ClockGame::MyClock &clock, sf::RenderWindow &window)
    {
        exComands();
        /*
        Update the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */

        // Update the delta time
        sf::Time dt = clock.restart();
        m_bat.update(dt);
        m_ball.update(dt);
        // Update the HUD text
        std::stringstream ss;
        ss << "Score:" << score.m_score << " Lives:" << score.m_lives << " Speed " << m_ball.getSpeed();
        m_hud.setString(ss.str());

        // Handle ball hitting the bottom
        if (m_ball.getPosition().top > static_cast<float>(window.getSize().y))
        {
            // reverse the ball direction
            m_ball.reboundBottom(1920 / 2,1080 / 2);
            m_ball.changeYdir();
            // Remove a life
            score.m_lives--;

            // Check for zero livesmm
            if (score.m_lives < 1)
            {
                score.reset();
            }
        }
        // Handle ball hitting the top
        if (m_ball.getPosition().top < 0)
        {
            // reverse the ball direction
            m_ball.reboundBatOrTop();

            score.m_score++;
        }
        // Handle ball hittint the sid of the screen
        if (m_ball.getPosition().left < 0 || m_ball.getPosition().left + m_ball.getPosition().width > static_cast<float>(window.getSize().x))
        {
            m_ball.reboundSides();
        }
        // Has the ball hit the bat ?
        if (m_ball.getPosition().intersects(m_bat.getPosition()))
        {
            // Hit dettected so reverse the ball and score a point
            m_ball.reboundBatOrTop();
        }
    }
    void exComands()
    {
        // Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_bat.moveLeft();
        }
        else
        {
            m_bat.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_bat.moveRight();
        }
        else
        {
            m_bat.stopRight();
        }
    }

    void render(sf::RenderWindow &window)
    { /* render logic for single player mode */
        window.clear();
        window.draw(m_hud);
        window.draw(m_bat.getShape());
        window.draw(m_ball.getShape());
        window.display();
    }
};

class MultiPlayer : public Player
{
private:
    struct Scores_Multiplayer
    /*
        Struct to hold the game score and the life of the player
    */
    {
        int m_score_player1;
        int m_score_player2;
        void reset()
        {
            m_score_player1 = 0;
            m_score_player2 = 0;
        }
    };
    Scores_Multiplayer score;
    Bat::Bat m_bat_p1; // Player on bottom
    Bat::Bat m_bat_p2; // Player on Top
    Ball::Ball m_ball;
    TextGame::MyText m_hud;

public:
    MultiPlayer() : m_bat_p1(1920 / 2, 1080 - 20), m_bat_p2(0, 20), m_ball(1920 / 2, 0), m_hud("fonts/DS-DIGI.TTF", 75, sf::Color::White, 20, 20)
    {
        score.reset();
    }
    void update(ClockGame::MyClock &clock, sf::RenderWindow &window)
    {
        exComands();

        // Update the delta time
        sf::Time dt = clock.restart();
        m_bat_p1.update(dt);
        m_bat_p2.update(dt);
        m_ball.update(dt);
        // Update the HUD text
        std::stringstream ss;
        ss << "Score P1:" << score.m_score_player1 << " Score P2:" << score.m_score_player2;
        m_hud.setString(ss.str());

        // Handle ball hitting the bottom player 2 won point
        if (m_ball.getPosition().top > static_cast<float>(window.getSize().y))
        {
            // reverse the ball direction
            m_ball.reboundBottom(1920 / 2,1080 / 2);

            score.m_score_player2++;
        }
        // Handle ball hitting the Player 1 Won point
        if (m_ball.getPosition().top < 0)
        {
            // reverse the ball direction
            m_ball.reboundTop(1920 / 2,1080 / 2);
            // reset the socre
            score.m_score_player1++;
        }
        // Handle ball hittint the sid of the screen
        if (m_ball.getPosition().left < 0 || m_ball.getPosition().left + m_ball.getPosition().width > static_cast<float>(window.getSize().x))
        {
            m_ball.reboundSides();
        }
        // Has the ball hit the bat ?
        if (m_ball.getPosition().intersects(m_bat_p1.getPosition()))
        {
            // Hit dettected so reverse the ball and score a point
            m_ball.reboundBat();
        }
        if (m_ball.getPosition().intersects(m_bat_p2.getPosition()))
        {
            // Hit dettected so reverse the ball and score a point
            m_ball.reboundBat();
        }
    }
    void exComands()
    {
        // Player1
        // Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_bat_p1.moveLeft();
        }
        else
        {
            m_bat_p1.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_bat_p1.moveRight();
        }
        else
        {
            m_bat_p1.stopRight();
        }

        // Player 2
        //  Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_bat_p2.moveLeft();
        }
        else
        {
            m_bat_p2.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_bat_p2.moveRight();
        }
        else
        {
            m_bat_p2.stopRight();
        }
    }
    void render(sf::RenderWindow &window)
    {
        window.clear();
        window.draw(m_hud);
        window.draw(m_ball.getShape());
        window.draw(m_bat_p1.getShape());
        window.draw(m_bat_p2.getShape());
        window.display();
    }
};
