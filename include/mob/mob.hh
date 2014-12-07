#ifndef MOB_HH
# define MOB_HH

# include <SFML/Graphics.hpp>
# include <memory>

# include "entity/entity.hh"
# include "mob/mob_stats.hh"
# include "mob/mob_type.hh"
# include "tower/tower_attack.hh"
# include "tower/tower.hh"

class Tower;

class Mob : public Entity
{
public:
  Mob(Point pos, MStats base_stats, mob_type type); /* FIXME add sprite */
  virtual ~Mob() override;

  MStats get_stats();
  void set_stats(MStats stats);
  Mob& operator+=(TAttack<Tower, Mob>& atk);
  int move(); //1 if reached, 0 else
  void set_dir(Point p);
  Point get_dir();
  void draw(sf::RenderWindow& window);

  static std::shared_ptr<Mob> get_goblin(Point p);
  static std::shared_ptr<Mob> get_minion(Point p);
  static std::shared_ptr<Mob> get_troll(Point p);
  static std::shared_ptr<Mob> get_skeleton(Point p);
  static std::shared_ptr<Mob> get_murloc(Point p);

private:
  MStats stats_;
  MStats real_stats_;
  Point dir_;
  mob_type type_;
  int move_ = 0;
};

#endif /* end of include guard: MOB_HH */
