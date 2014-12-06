#ifndef BUTTON_HH_
# define BUTTON_HH_

# include <vector>
# include <SFML/Graphics.hpp>
# include "game/action_types.hh"

/**
 * \brief Button class in this scope, turrets
 * are considered buttons since you can click on them
 * to display the upgrade menu
 */
class Button
{
public:
  Button() = default;
  Button(enum action action, sf::Vector2f pos,
         sf::RectangleShape shape, sf::Text text);

  enum action get_action() const;

  void draw(sf::RenderWindow& window);
  bool contains(sf::Vector2f vect);

  virtual ~Button() = default;

private:
  sf::Vector2f position_;
  sf::RectangleShape shape_;
  sf::Text text_;
  bool is_click_;
  enum action action_;
};

#endif /* !BUTTON_HH_ */
