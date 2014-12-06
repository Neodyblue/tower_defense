#include "mob/mob.hh"

Mob::Mob(Point pos, MStats base_stats) /* FIXME add sprite */
  : Entity(pos)
  , stats_(base_stats)
{}

Mob::~Mob()
{}

MStats Mob::get_stats()
{
  return stats_;
}

void Mob::set_stats(MStats stats)
{
  stats_ = stats;
}

Mob& Mob::operator+=(TAttack<Tower, Mob>& atk)
{
  stats_ += atk.get_diff();

  return *this;
}
