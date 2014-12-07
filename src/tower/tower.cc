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

Tower::~Tower()
{}

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
  if (!target_ || (clock_.getElapsedTime() - last_attack_).asMilliseconds()
      <= real_stats_.get_cooldown() || target_->get_stats().get_health() <= 0)
  {
    target_.reset();
    return std::shared_ptr<TAttack<Tower, Mob>>{};
  }

  last_attack_ = clock_.getElapsedTime();

  return (std::make_shared<TAttack<Tower, Mob>>(
          *this,
          target_,
          MStats(-base_stats_.get_damages(), 0, 0),
          real_stats_.get_radius()));
}

void Tower::draw(sf::RenderWindow& window)
{
  sf::CircleShape octagon(5, 8);
  octagon.setFillColor(sf::Color::Blue);
  octagon.setPosition(pos_.get_x() + 5, pos_.get_y() + 5);
  window.draw(octagon);
}
