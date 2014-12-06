#ifndef MOB_HH
# define MOB_HH

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

private:
  MStats stats_;
};

#endif /* end of include guard: MOB_HH */
