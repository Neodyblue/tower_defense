#include "mob/mob_stats.hh"

MStats::MStats(int health, int speed, bool fly)
  : health_(health)
  , speed_(speed)
  , fly_(fly)
{}

MStats& MStats::operator+=(MStats& other)
{
  return *this + other;
}

MStats& MStats::operator+(MStats& other)
{
  health_ += other.health_;
  speed_ += other.speed_;

  return *this;
}

MStats& MStats::operator-=(MStats& other)
{
  return *this - other;
}

MStats& MStats::operator-(MStats& other)
{
  health_ -= other.health_;
  speed_ -= other.speed_;

  return *this;
}

int MStats::get_health() const
{
  return health_;
}

int MStats::get_speed() const
{
  return speed_;
}

bool MStats::is_flying() const
{
  return fly_;
}
