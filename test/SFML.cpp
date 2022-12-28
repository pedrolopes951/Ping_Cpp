#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound/chop.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
       // sound.play(); // Turn down the volume trust me
    }
    
    assert(true==true);
    return 0;
}