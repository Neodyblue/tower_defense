#include <vector>
#include "game/create_buttons.hh"
#include "game/button.hh"

std::vector<std::shared_ptr<Button>> add_begin_buttons(sf::Font& f,
                                                       sf ::Vector2u win_size)
{
  std::vector<std::shared_ptr<Button>> sol;
  sf::RectangleShape button(sf::Vector2f(win_size.x / 4, win_size.y / 8));
  button.setFillColor(sf::Color(0, 0, 0, 200));
  button.setOutlineThickness(-10);
  button.setOutlineColor(sf::Color(0, 0, 0, 220));

  sf::Text text("Play", f, 24);
  text.setColor(sf::Color::Red);

  Button but(PLAY, sf::Vector2f(win_size.x / 2, win_size.y / 3),
             button, text);

  std::shared_ptr<Button> tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);

  button = sf::RectangleShape(sf::Vector2f(win_size.x / 4, win_size.y / 8));
  button.setFillColor(sf::Color(0, 0, 0, 200));
  button.setOutlineThickness(-10);
  button.setOutlineColor(sf::Color(0, 0, 0, 220));


  text = sf::Text("Quit", f, 24);
  text.setColor(sf::Color::Red);

  but = Button(QUIT, sf::Vector2f(win_size.x / 2, 2 * win_size.y / 3),
               button, text);


  tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);
  return sol;
}


std::vector<std::shared_ptr<Button>> add_game_buttons(sf::Font& f,
                                                      sf::Vector2u win_size)
{
  std::vector<std::shared_ptr<Button>> sol;
  sf::RectangleShape button(sf::Vector2f(win_size.x / 8, win_size.y / 16));
  button.setFillColor(sf::Color(200, 0, 0, 200));
  button.setOutlineThickness(-5);
  button.setOutlineColor(sf::Color(200, 0, 0, 220));

  sf::Text text("Menu", f, 24);
  text.setColor(sf::Color::Black);

  Button but(QUITMENU, sf::Vector2f(90 * win_size.x / 96, 22 * win_size.y / 32),
             button, text);

  std::shared_ptr<Button> tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);

  button = sf::RectangleShape(sf::Vector2f(win_size.x / 8, win_size.y / 16));
  button.setFillColor(sf::Color(0, 100, 0, 200));
  button.setOutlineThickness(-5);
  button.setOutlineColor(sf::Color(0, 100, 0, 220));


  text = sf::Text("Pause", f, 24);
  text.setColor(sf::Color::Black);

  but = Button(PAUSE, sf::Vector2f(39 * win_size.x / 48, 22 * win_size.y / 32),
               button, text);


  tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);
  return sol;
}


std::vector<std::shared_ptr<Button>> add_pause_buttons(sf::Font& f,
                                                       sf::Vector2u win_size)
{
  std::vector<std::shared_ptr<Button>> sol;
  sf::RectangleShape button(sf::Vector2f(win_size.x / 4, win_size.y / 4));
  button.setFillColor(sf::Color::White);

  sf::Text text("Play", f, 24);
  text.setColor(sf::Color::Black);

  Button but(PLAY, sf::Vector2f(win_size.x / 2, win_size.y / 3),
             button, text);

  std::shared_ptr<Button> tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);

  button = sf::RectangleShape(sf::Vector2f(win_size.x / 4, win_size.y / 4));
  button.setFillColor(sf::Color::White);

  text = sf::Text("Play", f, 24);
  text.setColor(sf::Color::Black);

  but = Button(QUIT, sf::Vector2f(win_size.x / 2, 2 * win_size.y / 3),
               button, text);


  tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);
  return sol;
}


std::vector<std::shared_ptr<Button>> add_over_buttons(sf::Font& f,
                                                      sf::Vector2u win_size)
{
  std::vector<std::shared_ptr<Button>> sol;
  sf::RectangleShape button(sf::Vector2f(win_size.x / 4, win_size.y / 4));
  button.setFillColor(sf::Color::White);

  sf::Text text("Play", f, 24);
  text.setColor(sf::Color::Black);

  Button but(PLAY, sf::Vector2f(win_size.x / 2, win_size.y / 3),
             button, text);

  std::shared_ptr<Button> tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);

  button = sf::RectangleShape(sf::Vector2f(win_size.x / 4, win_size.y / 4));
  button.setFillColor(sf::Color::White);

  text = sf::Text("Play", f, 24);
  text.setColor(sf::Color::Black);

  but = Button(QUIT, sf::Vector2f(win_size.x / 2, 2 * win_size.y / 3),
               button, text);


  tamere = std::make_shared<Button>(but);
  sol.push_back(tamere);
  return sol;
}
