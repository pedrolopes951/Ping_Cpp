#pragma once 
#include "Player.hpp"
#include <memory>

/**
 * @brief The State pattern allows you to encapsulate the behavior 
 * of a single player or multiplayer 
 * mode in a separate class and switch between them at runtime.
*/
enum class GameMode
{
        SINGLEPLAYER=1,
        MULTIPLAYER=2,
};
class Game
{
    private:
        std::shared_ptr<Player> currentMode;
    public:
        Game() { currentMode = std::make_shared<SinglePlayer>(); }
        void setMode(std::shared_ptr<Player> mode) { currentMode = mode; }
        void update(ClockGame::MyClock& clock,sf::RenderWindow &window) { currentMode->update(clock,window); }
        void render(sf::RenderWindow &window) { currentMode->render(window); }
};