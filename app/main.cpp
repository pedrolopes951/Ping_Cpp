#include "Bat.hpp"
#include "Ball.hpp"
#include "GameLibrary.hpp"
#include "InitMenu.hpp"
#include "Game.hpp"
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "chrono"
#include "StructGame.hpp"
#include <csignal>

int main()
{
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);
    // Create and open a window for the game
    sf::RenderWindow window(vm, "Pong", sf::Style::None);
    // Define here the Game mode
    Game game;
    // Create Menu for the Game
    InitMenu::Menu menu(window);
    // Here is our clock for timing everything
    ClockGame::MyClock clock;
    // If it is the first draw of the game set the mode
    int initGame = 0;
    while (window.isOpen())
    {
        sf::Event event;
        menu.Draw(event);
        if (initGame == 0)
        {
            menu.GetMode(game);
            initGame++;
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Quit the game when the window is closed bu the use mouse
                window.close();
                return EXIT_SUCCESS;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    menu.SetMenu();
                    menu.Draw(event);
                    menu.GetMode(game);
                    window.clear();

                }
            }
        }
        game.update(clock, window);
        game.render(window);
    }
    window.close();
    return 0;
}
