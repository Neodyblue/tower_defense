#include <SFML/Graphics.hpp>

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
  if (!target_)
    return std::shared_ptr<TAttack<Tower, Mob>>{};

  if (target_->get_stats().get_health() <= 0)
  {
    target_.reset();
    return std::shared_ptr<TAttack<Tower, Mob>>{};
  }

  if ((clock_.getElapsedTime() - last_attack_).asMilliseconds()
      <= real_stats_.get_cooldown())
  {
    return std::shared_ptr<TAttack<Tower, Mob>>{};
  }

  last_attack_ = clock_.getElapsedTime();

  return (std::make_shared<TAttack<Tower, Mob>>(
          *this,
          target_,
          MStats(0, -base_stats_.get_damages(), 0, 0),
          real_stats_.get_radius()));
}

void Tower::draw(sf::RenderWindow& window)
{
  sf::CircleShape octagon(5);
  if (type_ == WATER)
    octagon.setFillColor(sf::Color(0x9d, 0xae, 0xb3));
  else if (type_ == HUMAN)
    octagon.setFillColor(sf::Color(0xcc, 0xc0, 0x80));
  else if (type_ == WOOD)
    octagon.setFillColor(sf::Color(0x66, 0x8d, 0x5d));
  else if (type_ == MOUNTAIN)
    octagon.setFillColor(sf::Color(0xa0, 0x38, 0x43));
  else if (type_ == SUPER_WATER)
    octagon.setFillColor(sf::Color(0x7e, 0x90, 0x95));
  else if (type_ == SUPER_HUMAN)
    octagon.setFillColor(sf::Color(0xb0, 0x8d, 0x58));
  else if (type_ == SUPER_WOOD)
    octagon.setFillColor(sf::Color(0x64, 0x6c, 0x4d));
  else
    octagon.setFillColor(sf::Color(0x6f, 0x2e, 0x3f));

  octagon.setPosition(pos_.get_x() + 5, pos_.get_y() + 5);
  window.draw(octagon);
}

void Tower::draw_beam(sf::RenderWindow& window)
{

  if (!target_ || target_->get_stats().get_health() <= 0)
    return;

  sf::Vertex line[] =
  {
    sf::Vertex(sf::Vector2f(target_->get_pos().get_x(),
                            target_->get_pos().get_y())),
    sf::Vertex(sf::Vector2f(pos_.get_x() + 10, pos_.get_y() + 10))
  };

  for (auto& l : line)
  {
  if (type_ == WATER)
    l.color = sf::Color(0x9d, 0xae, 0xb3);
  else if (type_ == HUMAN)
    l.color = sf::Color(0xcc, 0xc0, 0x80);
  else if (type_ == WOOD)
    l.color = sf::Color(0x66, 0x8d, 0x5d);
  else if (type_ == MOUNTAIN)
    l.color = sf::Color(0xa0, 0x38, 0x43);
  else if (type_ == SUPER_WATER)
    l.color = sf::Color(0x7e, 0x90, 0x95);
  else if (type_ == SUPER_HUMAN)
    l.color = sf::Color(0xb0, 0x8d, 0x58);
  else if (type_ == SUPER_WOOD)
    l.color = sf::Color(0x64, 0x6c, 0x4d);
  else
    l.color = sf::Color(0x6f, 0x2e, 0x3f);
  }

  window.draw(line, 2, sf::Lines);
}

std::shared_ptr<Tower> Tower::get_evles(Point pos)
{
  return std::make_shared<Tower>(TStats(2, 200, 1, 2000), pos, WOOD, GROUND);
}

std::shared_ptr<Tower> Tower::get_dwarfes(Point pos)
{
  return std::make_shared<Tower>(TStats(4, 40, 1, 1000), pos,
                                 MOUNTAIN, GROUND);
}

std::shared_ptr<Tower> Tower::get_nagas(Point pos)
{
  return std::make_shared<Tower>(TStats(1, 100, 1, 500), pos,
                                 WATER, GROUND);
}

std::shared_ptr<Tower> Tower::get_humans(Point pos)
{
  return std::make_shared<Tower>(TStats(2, 100, 1, 1000), pos,
                                 HUMAN, GROUND);
}

std::shared_ptr<Tower> Tower::get_sniper(Point pos)
{
  return std::make_shared<Tower>(TStats(3, 500, 1, 2000), pos,
                                 SUPER_WOOD, GROUND);
}

std::shared_ptr<Tower> Tower::get_ballrog(Point pos)
{
  return std::make_shared<Tower>(TStats(8, 30, 1, 2500), pos,
                                 SUPER_MOUNTAIN, GROUND);
}

std::shared_ptr<Tower> Tower::get_nagas_king(Point pos)
{
  return std::make_shared<Tower>(TStats(5, 100, 1, 1000), pos,
                                 SUPER_WATER, GROUND);
}

std::shared_ptr<Tower> Tower::get_jaime(Point pos)
{
  return std::make_shared<Tower>(TStats(6, 60, 1, 1300), pos,
                                 SUPER_HUMAN, GROUND);
}

unsigned int Tower::get_tower_price(tower_type t)
{
  switch (t)
    {
    case HUMAN:
      return 50;

    case SUPER_HUMAN:
      return 300;

    case WATER:
      return 100;

    case SUPER_WATER:
      return 500;

    case MOUNTAIN:
      return 100;

    case SUPER_MOUNTAIN:
      return 600;

    case WOOD:
      return 75;

    case SUPER_WOOD:
      return 400;
    }
}
