#ifndef BUTTON_HH_
# define BUTTON_HH_

# include <vector>
# include <SFML/graphics.hpp>
# include "game/action_types.hh"

/**
 * \brief Button class in this scope, turrets
 * are considered buttons since you can click on them
 * to display the upgrade menu
 */
class Button
{
public:
  Button();
  Button(enum action action, sf::Vector2f pos,
         sf::Shape shape, sf::Text text);

  virtual ~Button();

private:
  sf::Vector2f position_;
  sf::Shape shape_;
  sf::Text text_;
  bool is_click_;
  enum action action_;
};

#endif /* !BUTTON_HH_ */
