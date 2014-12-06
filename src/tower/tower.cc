#include "tower/tower.hh"

Tower::Tower(TStats base_stats,
             Point pos,
             tower_type type
             tower_target_type target_type) /* FIXME add sprite */
  : level_(1)
  , target_(nullptr)
  , base_stats_(base_stats)
  , real_stats_(base_stats_)
  , type_(tower_type)
  , target_type_(target_type)
{
  last_attack_ = clock_.getElapsedTime();
}

std::shared_ptr<Mob> Tower::get_target() const
{
  return target_;
}

void Tower::set_target(std::shared_ptr<Mob> mob)
{
  target_ = mob;
}

bool Tower::is_target_reachable() const
{
  return (target_ && (target_->get_pos() - get_pos()).get_manhattan()
          <= base_stats_.get_range())
}

const TStats& Tower::get_base_stats() const
{
  return base_stats_;
}

const TStats& Tower::get_real_stats() const
{
  return real_stats_;
}

const int Tower::get_level() const
{
  return level_;
}

const tower_type& Tower::get_type() const
{
  return type_;
}

const tower_target_type& Tower::get_target_type() const
{
  return target_type_;
}

std::shared_ptr<Attack<Tower, Tower::Mob>> attack()
{
  if ((clock_.getElapsedTime() - last_attack_).asMilliseconds()
      <= real_stats_.get_cooldown())
    return std::shared_ptr{};

  return (shared_ptr<Attack<Tower, Mob>(*this,
                                        target_,
                                        MStats(-base_stats_.get_damages(),
                                               0,
                                               0)));
}
