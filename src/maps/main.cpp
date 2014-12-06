#include <SFML/Graphics.hpp>

#include "gen.hh"

int main()
{
    auto v = Gen::Generate(10, 10, 5);
    unsigned width = v->size();
    unsigned height = (*v)[0].size();
    sf::RenderWindow window(sf::VideoMode(width, height), "Test.");


    sf::RectangleShape rectangle(sf::Vector2f(1, 1));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (unsigned x = 0; x < width; x++)
            for (unsigned y = 0; y < height; y++)
            {
                unsigned value = (*v)[x][y];
                rectangle.setPosition(x, y);
                rectangle.setFillColor(sf::Color(value, value, value));
                window.draw(rectangle);
            }
        window.display();
    }

}
