#include <SFML/Graphics.hpp>
#include <iostream>

#include "map/map.hh"
#include "play/play.hh"

int main()
{
  Play p;
  sf::RenderWindow window(sf::VideoMode(640, 640), "Test.");
  window.setFramerateLimit(60);


  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    p.update();
    window.clear();
    p.draw(window);
    window.display();
  }

}
