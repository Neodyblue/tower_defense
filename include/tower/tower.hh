#ifndef TOWER_HH
# define TOWER_HH

# include <memory>
# include <SFML/System.hpp>

# include "mob/mob.hh"
# include "tower/tower_stats.hh"
# include "tower/tower_type.hh"
# include "tower/tower_target_type.hh"
# include "tower/tower_attack.hh"
# include "entity/entity.hh"

class Mob;

class Tower : public Entity
{
public:
  Tower(TStats base_stats,
        Point pos,
        tower_type type,
        tower_target_type target_type); /* FIXME add sprite */
  virtual ~Tower();

  std::shared_ptr<Mob> get_target();
  void set_target(std::shared_ptr<Mob> mob);
  bool is_target_reachable();
  TStats& get_base_stats();
  TStats& get_real_stats();
  int get_level();
  tower_type& get_type();
  tower_target_type& get_target_type();
  std::shared_ptr<TAttack<Tower, Mob>> attack();
  virtual void draw(sf::RenderWindow& window) override;
  virtual void draw_beam(sf::RenderWindow& window);

  static std::shared_ptr<Tower> get_evles(Point pos);
  static std::shared_ptr<Tower> get_dwarfes(Point pos);
  static std::shared_ptr<Tower> get_nagas(Point pos);
  static std::shared_ptr<Tower> get_humans(Point pos);
  static std::shared_ptr<Tower> get_sniper(Point pos);
  static std::shared_ptr<Tower> get_ballrog(Point pos);
  static std::shared_ptr<Tower> get_nagas_king(Point pos);
  static std::shared_ptr<Tower> get_jaime(Point pos);
  static std::shared_ptr<Tower> get_farme(Point pos);
  static std::shared_ptr<Tower> get_churche(Point pos);

  static unsigned int get_tower_price(tower_type t);

private:
  int level_;
  std::shared_ptr<Mob> target_;
  TStats base_stats_;
  TStats real_stats_;
  tower_type type_;
  tower_target_type target_type_;
  sf::Clock clock_;
  sf::Time last_attack_;
};

#endif /* end of include guard: TOWER_HH */
