#include <iostream>

#include "mob/mob.hh"

Mob::Mob(Point pos, MStats base_stats, mob_type type)
  : Entity(pos)
  , stats_(base_stats)
  , real_stats_(base_stats)
  , dir_(-1, -1)
  , type_(type)
{}

Mob::~Mob()
{}

MStats Mob::get_stats()
{
  return real_stats_;
}

void Mob::set_stats(MStats stats)
{
  stats_ = stats;
  real_stats_ = stats;
}

Mob& Mob::operator+=(TAttack<Tower, Mob>& atk)
{
  real_stats_ += atk.get_diff();

  return *this;
}

int Mob::move()
{
  Point aux = pos_;
  if ((aux - dir_).get_manhattan() <= real_stats_.get_speed() )
  {
    pos_ = dir_;
    return 1;
  }
  if (pos_.get_x() != dir_.get_x())
  {
    if (pos_.get_x() > dir_.get_x())
      pos_.set_x(pos_.get_x() - real_stats_.get_speed());
    else
      pos_.set_x(pos_.get_x() + real_stats_.get_speed());
  }
  else
  {
    if (pos_.get_y() > dir_.get_y())
      pos_.set_y(pos_.get_y() - real_stats_.get_speed());
    else
      pos_.set_y(pos_.get_y() + real_stats_.get_speed());
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

static sf::Color get_color(float coeff,sf::Color base)
{
  float r = base.r * coeff;
  float g = base.g * coeff;
  float b = base.b * coeff;

  return sf::Color(r, g, b);
}

void Mob::draw(sf::RenderWindow& window)
{
  sf::CircleShape square(5, 4);
  float coeff = 1.f * real_stats_.get_health() / stats_.get_health();

  switch (type_)
    {
    case GOBLIN:
      square.setFillColor(get_color(coeff, sf::Color::Red));
      break;
    case MINION:
      square.setFillColor(get_color(coeff, sf::Color::Magenta));
      break;
    case TROLL:
      square.setFillColor(get_color(coeff, sf::Color::Green));
      break;
    case SKELETON:
      square.setFillColor(get_color(coeff, sf::Color::White));
      break;
    case MURLOC:
      square.setFillColor(get_color(coeff, sf::Color::Blue));
      break;
    }

  square.setPosition(pos_.get_x() - 5, pos_.get_y() - 5);
  window.draw(square);
}

std::shared_ptr<Mob> Mob::get_goblin(Point p)
{
  return std::make_shared<Mob>(p, MStats(2, 3, 4, false), GOBLIN);
}

std::shared_ptr<Mob> Mob::get_minion(Point p)
{
  return std::make_shared<Mob>(p, MStats(1, 2, 2, false), MINION);
}

std::shared_ptr<Mob> Mob::get_troll(Point p)
{
  return std::make_shared<Mob>(p, MStats(20, 30, 1, false), TROLL);
}

std::shared_ptr<Mob> Mob::get_skeleton(Point p)
{
  return std::make_shared<Mob>(p, MStats(5, 5, 2, false), SKELETON);
}

std::shared_ptr<Mob> Mob::get_murloc(Point p)
{
  return std::make_shared<Mob>(p, MStats(50, 10, 2, false), MURLOC);
}
