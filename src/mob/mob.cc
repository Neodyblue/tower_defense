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
