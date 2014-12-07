#ifndef MOB_HH
# define MOB_HH

# include <SFML/Graphics.hpp>

# include "entity/entity.hh"
# include "mob/mob_stats.hh"
# include "tower/tower_attack.hh"
# include "tower/tower.hh"

class Tower;

class Mob : public Entity
{
public:
  Mob(Point pos, MStats base_stats); /* FIXME add sprite */
  virtual ~Mob() override;

  MStats get_stats();
  void set_stats(MStats stats);
  Mob& operator+=(TAttack<Tower, Mob>& atk);
  int move(); //1 if reached, 0 else
  void set_dir(Point p);
  Point get_dir();
  void draw(sf::RenderWindow& window);

private:
  MStats stats_;
  MStats real_stats_;
  Point dir_;
};

#endif /* end of include guard: MOB_HH */
