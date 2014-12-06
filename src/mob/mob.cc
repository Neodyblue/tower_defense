#include <iostream>

#include "mob/mob.hh"

Mob::Mob(Point pos, MStats base_stats) /* FIXME add sprite */
  : Entity(pos)
  , stats_(base_stats)
  , dir_(-1, -1)
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

int Mob::move()
{
  Point aux = pos_;
  if ((aux - dir_).get_manhattan() <= stats_.get_speed() )
  {
    pos_ = dir_;
    return 1;
  }
  if (pos_.get_x() != dir_.get_x())
  {
    if (pos_.get_x() > dir_.get_x())
      pos_.set_x(pos_.get_x() - stats_.get_speed());
    else
      pos_.set_x(pos_.get_x() + stats_.get_speed());
  }
  else
  {
    if (pos_.get_y() > dir_.get_y())
      pos_.set_y(pos_.get_y() - stats_.get_speed());
    else
      pos_.set_y(pos_.get_y() + stats_.get_speed());
  }
  return 0;
}

void Mob::set_dir(Point p)
{
  dir_ = p;
}

Point Mob::get_dir()
{
  return dir_;
}

void Mob::draw(sf::RenderWindow& window)
{
  sf::CircleShape octagon(5, 8);
  octagon.setFillColor(sf::Color::Black);
  octagon.setPosition(pos_.get_x() - 5, pos_.get_y() - 5);
  window.draw(octagon);
}
