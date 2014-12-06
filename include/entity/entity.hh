#ifndef ENTITY_HH
# define ENTITY_HH

# include "point.hh"

class Entity
{
public:
  Entity(Point pos); /* FIXME add sprite */
  virtual ~Entity();

  Point& get_pos();
  virtual void draw(/*FIXME param SFML */);

protected:
  Point pos_;
  /* FIXME type */ int sprite_;
};

#endif /* end of include guard: ENTITY_HH */
