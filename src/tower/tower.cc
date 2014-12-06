#include "tower/tower.hh"

Tower::Tower(TStats base_stats,
             Point pos,
             tower_type type,
             tower_target_type target_type) /* FIXME add sprite */
  : Entity(pos)
  , level_(1)
  , target_(nullptr)
  , base_stats_(base_stats)
  , real_stats_(base_stats_)
  , type_(type)
  , target_type_(target_type)
{
  last_attack_ = clock_.getElapsedTime();
}

std::shared_ptr<Mob> Tower::get_target()
{
  return target_;
}

void Tower::set_target(std::shared_ptr<Mob> mob)
{
  target_ = mob;
}

bool Tower::is_target_reachable()
{
  return (target_ && (target_->get_pos() - pos_).get_manhattan()
          <= base_stats_.get_range());
}

TStats& Tower::get_base_stats()
{
  return base_stats_;
}

TStats& Tower::get_real_stats()
{
  return real_stats_;
}

int Tower::get_level()
{
  return level_;
}

tower_type& Tower::get_type()
{
  return type_;
}

tower_target_type& Tower::get_target_type()
{
  return target_type_;
}

std::shared_ptr<TAttack<Tower, Mob>> Tower::attack()
{
  if ((clock_.getElapsedTime() - last_attack_).asMilliseconds()
      <= real_stats_.get_cooldown())
    return std::shared_ptr<TAttack<Tower, Mob>>{};

  return (std::make_shared<TAttack<Tower, Mob>>(
        *this,
        *target_,
        MStats(base_stats_.get_damages(), 0, 0),
        real_stats_.get_radius()));
}