#include "entity/entity.hh"


Entity::Entity(Point pos) /* FIXME add sprite */
  : pos_(pos)
{}

Entity::~Entity()
{}

Point& Entity::get_pos()
{
  return pos_;
}

void Entity::draw() /* FIXME param SFML */
{}
