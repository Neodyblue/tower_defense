#ifndef TOWER_ATTACK_HH
# define TOWER_ATTACK_HH

# include <memory>

# include "mob/mob_stats.hh"

template<class T, class M>
class TAttack
{
public:
  TAttack(T& origin,
          std::shared_ptr<M> target,
          MStats diff,
          int zone);

  T& get_origin();
  std::shared_ptr<M> get_target();
  MStats& get_diff();
  int& get_zone();

private:
  T origin_;
  std::shared_ptr<M> target_;
  MStats diff_;
  int zone_;
};

# include "tower/tower_attack.hxx"

#endif /* end of include guard: TOWER_ATTACK_HH */
