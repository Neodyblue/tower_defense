#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Best Game");

  sf::RectangleShape button(sf::Vector2f(100, 50));

  button.setFillColor(sf::Color(100, 250, 50));

  button.setPosition(350, 250);

  sf::Font font;

  if (!font.loadFromFile("../../res/Livingst.ttf"))
    return 1;

  sf::Text quit_text("Quit", font, 24);
  quit_text.setPosition(375, 260);
  quit_text.setColor(sf::Color::Black);

  sf::Text success_text("fail", font, 24);
  success_text.setPosition(200, 200);
  success_text.setColor(sf::Color::Red);

  sf::Texture bg_image;
  if (!bg_image.loadFromFile("../../res/n_background_menu.jpg"))
      return 1;
      sf::Sprite sprite(bg_image);

  sf::FloatRect button_bounds = button.getGlobalBounds();

  while (window.isOpen())
  {
  button.setFillColor(sf::Color(100, 250, 50));

    sf::Event event;

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    sf::Vector2f temp =  sf::Vector2f::Vector2(sf::Mouse::getPosition(window));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && button_bounds.contains(temp))
    {
      success_text.setString("Success!!");
      button.setFillColor(sf::Color::Blue);
    }

    window.clear();
    window.draw(sprite);
    window.draw(button);
    window.draw(quit_text);
    window.draw(success_text);
    window.display();


  }


  return 0;
}
