#ifndef TOWER_HH
# define TOWER_HH

# include <memory>
# include <SFML/Clock.hpp>

# include "mob/mob.hh"
# include "tower/tower_stats.hh"
# include "tower/tower_type.hh"
# include "tower/tower_target_type.hh"
# include "tower/tower_attack.hh"
# include "entity/entity.hh"

class Tower : public Entity
{
public:
  Tower(TStats base_stats,
        Point pos,
        tower_type type,
        tower_target_type target_type); /* FIXME add sprite */

  std::shared_ptr<Mob> get_target() const;
  void set_target(std::shared_ptr<Mob> mob);
  bool is_target_reachable() const;
  const TStats& get_base_stats() const;
  const TStats& get_real_stats() const;
  const int get_level() const;
  const tower_type& get_type() const;
  const tower_target_type& get_target_type() const;
  std::shared_ptr<Attack<Tower, Mob>> attack();

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
