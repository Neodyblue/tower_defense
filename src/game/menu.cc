# include <memory>
# include <vector>
# include <SFML/Graphics.hpp>
#include "game/create_buttons.hh"
#include "game/menu_types.hh"
#include "game/menu.hh"
#include "game/button.hh"
#include "game/action_types.hh"

Menu::Menu(sf::Texture& sprite, enum menu_type type) : texture_(sprite),
                                                      bg_img_(texture_),
                                                      type_(type)
{
  sf::FloatRect rect = bg_img_.getGlobalBounds();

  bg_img_.setScale(1280 / rect.width, 1024 / rect.height);
}

void Menu::draw(sf::RenderWindow& window) const
{
  window.draw(bg_img_);
  for (std::shared_ptr<Button> but : buttons_)
  {
    (*but).draw(window);
  }
}

void Menu::add_button(Button but)
{
  std::shared_ptr<Button> sol = std::make_shared<Button>(but);
  buttons_.push_back(sol);
}

enum action Menu::get_action(sf::Vector2f temp)
{
  for (std::shared_ptr<Button> but : buttons_)
  {
    if (but->contains(temp))
      return but->get_action();
  }
  return NIL;
}

enum menu_type Menu::get_type() const
{
  return type_;
}

void Menu::init_buttons(sf::Font& f, sf::Vector2u win_size)
{
  if (type_ == BEGINM)
    buttons_ = add_begin_buttons(f, win_size);
  else if (type_ == GAMEM)
    buttons_ = add_game_buttons(f, win_size);
  else if (type_ == PAUSEM)
    buttons_ = add_pause_buttons(f, win_size);
  else
    buttons_ = add_over_buttons(f, win_size);
}
