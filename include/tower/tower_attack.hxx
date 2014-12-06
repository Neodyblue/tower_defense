#ifndef TOWER_ATTACK_HXX
# define TOWER_ATTACK_HXX

# include "tower/tower_attack.hh"

template<class T, class M>
TAttack<T, M>::TAttack(T origin, M target, MStats diff, int zone)
  : origin_(origin)
  , target_(target)
  , diff(diff)
  , zone_(zone)
{}

template<class T, class M>
T& TAttack<T, M>::get_origin() const
{
  return origin_;
}

template<class T, class M>
M& TAttack<T, M>::get_target() const
{
  return target_;
}

template<class T, class M>
MStats& TAttack<T, M>::get_diff() const
{
  return diff_;
}

template<class T, class M>
int& TAttack<T, M>::get_zone() const
{
  return zone_;
}

#endif /* end of include guard: TOWER_ATTACK_HXX */
