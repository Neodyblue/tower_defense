#ifndef TOWER_ATTACK_HH
# define TOWER_ATTACK_HH

# include "mob/mob_stats.hh"

template<class T, class M>
class TAttack
{
public:
  TAttack(T origin, M target, MStats diff, int zone);

  T& get_origin();
  M& get_target();
  MStats& get_diff();
  int& get_zone();

private:
  T origin_;
  M target_;
  MStats diff_;
  int zone_;
};

# include "tower/tower_attack.hxx"

#endif /* end of include guard: TOWER_ATTACK_HH */
