#ifndef MENU_HH_
# define MENU_HH_

# include <vector>
# include <SFML/graphics.hpp>
# include "game/menu_types.hh"


/**
 * \brief Menu class. Its goal is to handle the various
 * Menus. The difference betweend the various menus being
 * quite small given the flexibility of this class, we decided
 * to skip the inheritance part.
 */
class Menu : Drawable
{
public:
  Menu();
  Menu(std::string sprite, enum menu_type type);
  void init_buttons();
  enum action get_action(sf::Vector2f temp);
  virtual ~Menu();

private:
  std::vector<Buttons> buttons_;
  sf::Sprite bg_img_;
  enum menu_type type_;
};

#endif /* !MENU_HH_ */
