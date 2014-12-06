#ifndef MENU_HH_
# define MENU_HH_

# include <memory>
# include <vector>
# include <SFML/Graphics.hpp>
# include "game/button.hh"
# include "game/action_types.hh"
# include "game/menu_types.hh"


/**
 * \brief Menu class. Its goal is to handle the various
 * Menus. The difference betweend the various menus being
 * quite small given the flexibility of this class, we decided
 * to skip the inheritance part.
 */
class Menu
{
public:
  Menu() = default;
  Menu(sf::Texture sprite, enum menu_type type);
  void add_button(Button but);
  enum action get_action(sf::Vector2f temp);
  void draw(sf::RenderWindow& window) const;
  void init_buttons(sf::Font& f, sf::Vector2u win_size);

  enum menu_type get_type() const;
  virtual ~Menu() = default;


private:
  std::vector<std::shared_ptr<Button>> buttons_;
  sf::Texture texture_;
  sf::Sprite bg_img_;
  enum menu_type type_;
};

#endif /* !MENU_HH_ */
