#include "game/button.hh"
#include "game/menu.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 1024), "Best Game");

  sf::Font font;

  if (!font.loadFromFile("../../res/Livingst.ttf"))
    return 1;

/*  sf::RectangleShape button(sf::Vector2f(100, 50));
  button.setFillColor(sf::Color(100, 250, 50));

  sf::Text quit_text("Quit", font, 24);
  quit_text.setColor(sf::Color::Black);*/

  sf::Texture bg_image;
  if (!bg_image.loadFromFile("../../res/n_background_menu.jpg"))
      return 1;

  sf::Texture play_image;
  if (!play_image.loadFromFile("../../res/troll.jpg"))
    return 1;

//  Button but(QUIT, sf::Vector2f(400, 300), button, quit_text);

  std::map<std::string, std::shared_ptr<Menu>> menus;

  std::shared_ptr<Menu> menu = std::make_shared<Menu>(bg_image, BEGINM);
  std::pair<std::string, std::shared_ptr<Menu>> temp("begin", menu);

  menus.insert(temp);

  menu = std::make_shared<Menu>(play_image, GAMEM);
  menu->init_buttons(font, window.getSize());

  temp = std::pair<std::string, std::shared_ptr<Menu>>("play", menu);
  menus.insert(temp);

  menu = menus["begin"];
// menu.add_button(but);
  menu->init_buttons(font, window.getSize());

  while (window.isOpen())
  {

    sf::Vector2f temp =  sf::Vector2f::Vector2(sf::Mouse::getPosition(window));

    enum action act = menu->get_action(temp);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (act == QUIT)
      {
        window.clear();
        window.close();
      }
      if (act == PLAY)
      {
        menu = menus["play"];
      }
    }

    window.clear();
    menu->draw(window);
    window.display();


  }

  return 0;
}
