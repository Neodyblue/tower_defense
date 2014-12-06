#include "tower/tower_stats.hh"

TStats::TStats(int damages, int range, int radius, int cooldown)
  : damages_(damages)
  , range_(range)
  , radius_(radius)
  , cooldown_(cooldown)
{}


TStats& TStats::operator+=(TStats& other)
{
  return *this + other;
}

TStats& TStats::operator+(TStats& other)
{
  damages_ += other.damages_;
  range_ += other.range_;
  radius_ += other.radius_;
  cooldown_ += other.cooldown_;

  return *this;
}

TStats& TStats::operator-=(TStats& other)
{
  return *this - other;
}

TStats& TStats::operator-(TStats& other)
{
  damages_ -= other.damages_;
  range_ -= other.range_;
  radius_ -= other.radius_;
  cooldown_ -= other.cooldown_;

  return *this;
}

const int get_damages() const
{
  return damages_;
}

const int get_range() const
{
  return range_;
}

const int get_radius() const
{
  return range_;
}

const int get_cooldown() const
{
  return cooldown_;
}
