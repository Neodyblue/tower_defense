#ifndef TOWER_ATTACK_HXX
# define TOWER_ATTACK_HXX

# include "tower/tower_attack.hh"

template<class T, class M>
TAttack<T, M>::TAttack(T& origin,
                       std::shared_ptr<M> target,
                       MStats diff,
                       int zone)
  : origin_(origin)
  , target_(target)
  , diff_(diff)
  , zone_(zone)
{}

template<class T, class M>
T& TAttack<T, M>::get_origin()
{
  return origin_;
}

template<class T, class M>
std::shared_ptr<M> TAttack<T, M>::get_target()
{
  return target_;
}

template<class T, class M>
MStats& TAttack<T, M>::get_diff()
{
  return diff_;
}

template<class T, class M>
int& TAttack<T, M>::get_zone()
{
  return zone_;
}

#endif /* end of include guard: TOWER_ATTACK_HXX */
