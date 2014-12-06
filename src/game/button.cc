#include "game/button.hh"

void set_center_origin(sf::Text& test)
{
  sf::FloatRect size = test.getLocalBounds();
  test.setOrigin(test.getOrigin().x + (size.width / 2),
                 test.getOrigin().y + (size.height / 2));
}

void set_center_origin(sf::Shape& test)
{
  sf::FloatRect size = test.getGlobalBounds();
  test.setOrigin(test.getOrigin().x + (size.width / 2),
                 test.getOrigin().y + (size.height / 2));
}

Button::Button(enum action action, sf::Vector2f pos,
               sf::RectangleShape shape, sf::Text text) : position_(pos),
                                                          shape_(shape),
                                                          text_(text),
                                                          is_click_(false),
                                                          action_(action)
{

  set_center_origin(shape_);
  shape_.setPosition(pos);
  set_center_origin(text_);
  text_.setPosition(shape_.getPosition().x,
                    shape_.getPosition().y);
}

void Button::draw(sf::RenderWindow& window)
{
  window.draw(shape_);
  window.draw(text_);
}

enum action Button::get_action() const
{
  return action_;
}

sf::Color get_inverse_col(sf::Color col1)
{
  return sf::Color(255 - col1.r, 255 - col1.g, 255 - col1.b, 255 - col1.a);
}

bool Button::contains(sf::Vector2f vect)
{
  if (is_click_)
  {
    is_click_ = false;;
    shape_.setFillColor(get_inverse_col(shape_.getFillColor()));
  }


  sf::FloatRect bounds = shape_.getGlobalBounds();
  if (bounds.contains(vect))
  {
    is_click_ = true;
    shape_.setFillColor(get_inverse_col(shape_.getFillColor()));
    return true;
  }
  return false;
}
