#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.hh"

int main()
{
    auto v = Map(5, 5, 7);
    unsigned width = v.get_width();
    unsigned height = v.get_height();

    std::cout << "Finis" << std::endl;

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
        v.draw(window);
        window.display();
    }

}
