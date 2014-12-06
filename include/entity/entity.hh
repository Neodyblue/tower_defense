#ifndef ENTITY_HH
# define ENTITY_HH

# include <SFML/Graphics.hpp>

# include "point.hh"

class Entity
{
public:
  Entity(Point pos); /* FIXME add sprite */
  virtual ~Entity();

  Point get_pos();
  void set_pos(Point pos);
  virtual void draw(sf::RenderWindow& window);

protected:
  Point pos_;
  /* FIXME type */ int sprite_;
};

#endif /* end of include guard: ENTITY_HH */
