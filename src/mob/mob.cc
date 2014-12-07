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
  move_++;
  int speed = real_stats_.get_speed() / 2;
  speed += move_ % 2;
  Point aux = pos_;
  if ((aux - dir_).get_manhattan() <= speed)
  {
    pos_ = dir_;
    return 1;
  }
  if (pos_.get_x() != dir_.get_x())
  {
    if (pos_.get_x() > dir_.get_x())
      pos_.set_x(pos_.get_x() - speed);
    else
      pos_.set_x(pos_.get_x() + speed);
  }
  else
  {
    if (pos_.get_y() > dir_.get_y())
      pos_.set_y(pos_.get_y() - speed);
    else
      pos_.set_y(pos_.get_y() + speed);
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
      square.setFillColor(get_color(coeff, sf::Color(0xba, 0x42, 0x45)));
      break;
    case MINION:
      square.setFillColor(get_color(coeff, sf::Color(0x6f, 0x2e, 0x3f)));
      break;
    case TROLL:
      square.setFillColor(get_color(coeff, sf::Color(0x42, 0x61, 0x46)));
      break;
    case SKELETON:
      square.setFillColor(get_color(coeff, sf::Color(0xe5, 0xc4, 0xa4)));
      break;
    case MURLOC:
      square.setFillColor(get_color(coeff, sf::Color(0x4a, 0x70, 0x69)));
      break;
    }

  square.setOutlineColor(sf::Color(0xc4, 0xc2, 0xb4, 100));
  square.setOutlineThickness(-1);
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
