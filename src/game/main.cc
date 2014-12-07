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
  sf::Clock clock;
  sf::Time time = clock.getElapsedTime();;
  bool pause = true;
  std::shared_ptr<Menu> menu;


  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(1280, 1024), "Best Game",
                          sf::Style::Default, settings);

  sf::Font font;

  if (!font.loadFromFile("./res/Livingst.ttf"))
    return 1;
  sf::Text status_text("", font, 42);
  status_text.setColor(sf::Color::Red);
  status_text.setPosition(550, 0);
  sf::Texture bg_image;
  if (!bg_image.loadFromFile("./res/n_background_menu.jpg"))
      return 1;

  sf::Texture play_image;
  if (!play_image.loadFromFile("./res/scroll_test.png"))
    return 1;


  std::map<std::string, std::shared_ptr<Menu>> menus;

  menus.insert(init_menus(bg_image, BEGINM, font, window.getSize()));
  menus.insert(init_menus(play_image, GAMEM, font, window.getSize()));

  menu = menus["begin"];

  menu->draw(window);
  window.display();
  Play p{};


  while (window.isOpen())
  {

    sf::Vector2f temp = sf::Vector2f::Vector2(sf::Mouse::getPosition(window));

    enum action act = menu->get_action(temp);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && (clock.getElapsedTime() - time).asMilliseconds() >= 200.0f)
    {
      time = clock.getElapsedTime();

      if (act == QUIT)
        window.close();

      if (act == PLAY)
        menu = menus["play"];

      if (act == QUITMENU)
        menu = menus["begin"];
      if (act == PAUSE)
      {
        if (!(pause = !pause))
          status_text.setString("Game Paused");
        else
          status_text.setString("");
      }
    }

    window.clear();
    menu->draw(window);


    if (menu->get_type() == GAMEM)
    {
      p.input(window);
      if (pause)
        p.update();
      p.draw(window, font);
    }
    window.draw(status_text);
    window.display();
  }

  return 0;
}
