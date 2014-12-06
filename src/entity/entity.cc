#include "entity/entity.hh"


Entity::Entity(Point pos) /* FIXME add sprite */
  : pos_(pos)
{}

Entity::~Entity()
{}

Point Entity::get_pos()
{
  return pos_;
}

void Entity::set_pos(Point pos)
{
  pos_ = pos;
}

void Entity::draw(sf::RenderWindow& window)
{
  sf::CircleShape octagon(5, 8);
  octagon.setFillColor(sf::Color::Black);
  octagon.setPosition(pos_.get_x() + 5, pos_.get_y() + 5);
  window.draw(octagon);
}
