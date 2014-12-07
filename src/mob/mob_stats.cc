#include "mob/mob_stats.hh"

MStats::MStats(int str, int health, int speed, bool fly)
  : health_(health)
  , strength_(str)
  , speed_(speed)
  , fly_(fly)
{
  gold_ = health * speed;
}

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

int MStats::get_strength() const
{
  return strength_;
}

int MStats::get_health() const
{
  return health_;
}

int MStats::get_speed() const
{
  return speed_;
}

int MStats::get_gold() const
{
  return gold_;
}

bool MStats::is_flying() const
{
  return fly_;
}
