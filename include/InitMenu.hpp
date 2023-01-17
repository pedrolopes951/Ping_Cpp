#pragma once 
#include <SFML/Graphics.hpp>
#include "GameLibrary.hpp"
#include <string>

/**
 *@brief
 */

namespace InitMenu
{

    // Class which handle the menu of the game
    // construcotr will can initialize object of the class Text (GameLibrary)
    // and will center the menu on the center of the screen
    // Call a method Input from user
    // Input method will wait for the user to press a key from the user menu
    // 1 - Start the SinglePlayer mode
    // 2 - Start the Multiplayer mode
    // 3 - Quit the Game and Close the window
    // 9 - Pause the Game from any time of the game (Caputure the keypress and then call this method)
    class Menu
    {
    private:
        bool m_begin_game = true;
        const TextGame::MyText &m_menu_text;
        sf::RenderWindow &m_window;
        sf::RectangleShape m_menu_background;

    public:
        Menu(sf::RenderWindow &window, const TextGame::MyText &text);
        void Draw();
        void Start();
        ~Menu();
    };

    Menu::Menu(sf::RenderWindow &window, const TextGame::MyText &text) : m_menu_text{text}, m_window{window}, m_menu_background(sf::Vector2f(200, 100))
    {
        // Center and set the Menu of the game
        // m_menu_background.setOrigin(static_cast<float>(m_menu_background.getSize().x / 2.0), static_cast<float>(m_menu_background.getSize().y / 2.0));
        m_menu_background.setPosition(static_cast<float>(((float)window.getSize().x - m_menu_background.getSize().x) / 2.0), static_cast<float>(((float)window.getSize().y - m_menu_background.getSize().y) / 2.0));
        m_menu_background.setFillColor(sf::Color::Red);
        m_menu_background.setOutlineThickness(2);
        m_menu_background.setOutlineColor(sf::Color::Green);
        
    }
    Menu::~Menu()
    {
    }

    void Menu::Draw()
    {
        while (m_begin_game)
        {
            Start();
        }
    }

    void Menu::Start()
    {

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Quit the game when the window is closed
                m_window.close();
        }
        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            m_begin_game = false;
        }
        m_window.draw(m_menu_background);
        m_window.display();
    }

}
