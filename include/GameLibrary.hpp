#include <SFML/Graphics.hpp>
#include "iostream"
#include <string>

namespace TextGame
{
    /**
     * @brief TextGame is Responsible for creating all the sf::text and sf::font object responsible
     * for the HUD of the game. It functiones as a wrappet to the sf::text and sf::font
    */
    class Text : public sf::Text, public sf::Font
    {
    public:
        explicit Text(std::string_view font_path, int16_t char_size,const sf::Color &color_text, float x_pos, float y_pos);
        ~Text(){};       
    };
};


namespace Clock
{
    class Clock : public sf::Clock
    {
        
    };
};