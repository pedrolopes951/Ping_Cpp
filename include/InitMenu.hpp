#pragma once
#include <SFML/Graphics.hpp>
#include "GameLibrary.hpp"
#include "Game.hpp"
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
        bool m_menu_show = true;
        TextGame::MyText m_menu_text;
        sf::RenderWindow& m_window;
        sf::RectangleShape m_menu_background;
        std::vector<sf::Text> m_menuOptions{};
        void DrawMenuOptions();
        void SetTextPosition(std::vector<sf::Text> &menuOptions);
        void Start(sf::Event &event);
        GameMode m_game_mode;

    public:
        Menu(sf::RenderWindow &window);
        void SetMenu();
        void GetMode(Game& mode);
        std::shared_ptr<Player> GetModePtr();
        void Draw(sf::Event &event);
        ~Menu();
    };

    Menu::Menu(sf::RenderWindow &window) :m_menu_text(std::string_view("fonts/DS-DIGI.TTF"), 75, sf::Color::White, 20,20), m_window(window),m_menu_background(sf::Vector2f(600, 400))
    {
        // Center and set the Menu of the game
        m_menu_background.setPosition(static_cast<float>(((float)window.getSize().x - m_menu_background.getSize().x) / 2.0), static_cast<float>(((float)window.getSize().y - m_menu_background.getSize().y) / 2.0));
        m_menu_background.setFillColor(sf::Color::Red);
        m_menu_background.setOutlineThickness(2);
        m_menu_background.setOutlineColor(sf::Color::Green);
        DrawMenuOptions();
    }
    Menu::~Menu()
    {
    }

    void Menu::Draw(sf::Event &event)
    {
        while (m_menu_show)
        {
            Start(event);
        }
    }

    void Menu::SetMenu()
    {
        m_menu_show = true;
    }
    void Menu::Start(sf::Event &event)
    {

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Quit the game when the window is closed
                m_window.close();
                return;
            }
        }
        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
        {
            m_window.close();
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
        {
            m_game_mode = GameMode::SINGLEPLAYER;
            m_menu_show = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
        {
            m_game_mode = GameMode::MULTIPLAYER;
            m_menu_show = false;
        }

        m_window.clear();
        m_window.draw(m_menu_background);
        for (auto &i : m_menuOptions)
        {
            m_window.draw(i);
        }

        m_window.display();
    }

    void Menu::GetMode(Game& mode)
    {
        if (m_game_mode ==  GameMode::SINGLEPLAYER)
        {
            mode.setMode(std::make_shared<SinglePlayer>());
        }
        else{
            mode.setMode(std::make_shared<MultiPlayer>());        
        }
    }

    void Menu::DrawMenuOptions()
    {
        std::vector<std::string> options = {"1- SinglePlayer", "2- Multiplayer", "3- Quit the Game"};

        for (auto option : options)
        {
            sf::Text text;
            text.setString(option);
            text.setFont(*m_menu_text.getFont());
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Black);
            m_menuOptions.push_back(text);
        }
        SetTextPosition(m_menuOptions);
    }
    void Menu::SetTextPosition(std::vector<sf::Text> &menuOptions)
    {
        // Location of the BackgroundSizes
        sf::Vector2f menuBackgroundSize = m_menu_background.getSize();
        sf::Vector2f menuBackgroundPosition = m_menu_background.getPosition();

        // Calculate the center position of the menu background
        sf::Vector2f center((float)menuBackgroundPosition.x + menuBackgroundSize.x / 2, (float)menuBackgroundPosition.y + menuBackgroundSize.y / 2);

        // Set the position of the menu options
        float index = 0.0f;
        for (auto &option : menuOptions)
        {
            sf::FloatRect textRect = option.getLocalBounds();
            option.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            option.setPosition(center.x, center.y - (menuBackgroundSize.y / 2.0f - 100.0f) + (index * 30.0f) / 2.0f + (float)option.getCharacterSize() * index);
            index++;
        }
    }
}
