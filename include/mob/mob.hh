#ifndef MOB_HH
# define MOB_HH

# include "entity/entity.hh"
# include "mob/mob_stats.hh"

class Mob : public Entity
{
public:
  Mob(Point pos, MStats base_stats); /* FIXME add sprite */
  virtual ~Mob() override;
  MStats get_stats();

private:
  MStats stats_;
};

#endif /* end of include guard: MOB_HH */
