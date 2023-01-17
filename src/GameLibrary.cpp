#include "GameLibrary.hpp"

namespace TextGame
{
    MyText::MyText(std::string_view font_path,int16_t char_size,const sf::Color &color_text, float x_pos, float y_pos)
    {
       if(!loadFromFile(std::string(font_path)))
       {
            //Handle Erro
            std::cerr << "Errro loading the font path" << std::endl;
       }

       setFont(*this);
       setCharacterSize(char_size);
       setFillColor(color_text);
       setPosition(x_pos,y_pos);


    }
    
};


namespace Clock
{
    
};