#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "chrono"
#include "StructGame.hpp"
#include <thread>


int main()
{
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);
    // Create and open a window for the game
    sf::RenderWindow window(vm, "Pong", sf::Style::Default);

    ScoreGame::Scores game_score(0,6);
    // Create a bat at the bottom center of the screen
    BatClass::Bat bat(1920 / 2, 1080 - 20);
    // We will add a ball in the next chapter
    // Create a Text object called HUD
    Text::Text hud;
    // A cool retro-style font
    Font::Font font;
    font.loadFromFile("fonts/DS-DIGI.TTF");
    // Set the font to our retro-style
    hud.setFont(font);
    // Make it nice and big
    hud.setCharacterSize(75);
    // Choose a color
    hud.setFillColor(sf::Color::White);
    hud.setPosition(20, 20);
    // Here is our clock for timing everything
    Clock::Clock clock;
    while (window.isOpen())
    {
        /*
        Handle the player input
        ****************************
        ****************************
        ****************************
        */
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }
        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        // Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        /*
        Update the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */
        // Update the delta time
        sf::Time dt = clock.restart();
        bat.update(dt);
        // Update the HUD text
        std::stringstream ss;
        ss << "Score:" << game_score.m_score << " Lives:" << game_score.m_lives;
        hud.setString(ss.str());
        /*
        Draw the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }
    return 0;
}