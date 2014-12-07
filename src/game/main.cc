#include "game/button.hh"
#include "game/menu.hh"
#include "play/play.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>

std::pair<std::string, std::shared_ptr<Menu>> init_menus(sf::Texture& bg_img,
                                                         enum menu_type type,
                                                         sf::Font& f,
                                                         sf::Vector2u v)
{
  std::shared_ptr<Menu> menu = std::make_shared<Menu>(bg_img, type);

  menu->init_buttons(f, v);

  if (type == BEGINM)
    return std::pair<std::string, std::shared_ptr<Menu>>("begin", menu);

  if (type == GAMEM)
    return std::pair<std::string, std::shared_ptr<Menu>>("play", menu);

  return std::pair<std::string, std::shared_ptr<Menu>>("troll", menu);
}

int main()
{
  std::shared_ptr<Menu> menu;

  sf::RenderWindow window(sf::VideoMode(1280, 1024), "Best Game");

  sf::Font font;

  if (!font.loadFromFile("./res/Livingst.ttf"))
    return 1;

  sf::Texture bg_image;
  if (!bg_image.loadFromFile("./res/n_background_menu.jpg"))
      return 1;

  sf::Texture play_image;
  if (!play_image.loadFromFile("./res/n_background_menu.jpg"))
    return 1;

//  Button but(QUIT, sf::Vector2f(400, 300), button, quit_text);

  std::map<std::string, std::shared_ptr<Menu>> menus;

  menus.insert(init_menus(bg_image, BEGINM, font, window.getSize()));
  menus.insert(init_menus(play_image, GAMEM, font, window.getSize()));

  menu = menus["begin"];
// menu.add_button(but);

  menu->draw(window);
  window.display();
  Play p{};


  while (window.isOpen())
  {

    sf::Vector2f temp = sf::Vector2f::Vector2(sf::Mouse::getPosition(window));

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

    if (menu->get_type() == GAMEM)
    {
      p.update();
      p.draw(window);
    }
    window.display();
  }

  return 0;
}
