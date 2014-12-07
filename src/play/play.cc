#include <SFML/Window.hpp>
#include <iostream>
#include "tower/tower_type.hh"

#include "play/play.hh"

Play::Play()
  : map_(10, 5, 7)
  , counter_(0)
{
  portals_ = map_.get_portals();
  nexus_ = map_.and_get();
}

void Play::input(sf::RenderWindow& window)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
    selected_tower_ = 0;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    selected_tower_ = 1;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    selected_tower_ = 2;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    selected_tower_ = 3;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    selected_tower_ = 4;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    selected_tower_ = 5;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
    selected_tower_ = 6;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
    selected_tower_ = 7;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    selected_tower_ = 8;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
    selected_tower_ = 9;

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
  {
    sf::Vector2i v = sf::Mouse::getPosition(window);
    Point p(v.x, v.y);
    tower_type t = HUMAN;
    if (map_.can_build(p, t))
    {
      p = map_.get_build_position(p);
      towers_.push_back(std::make_shared<Tower>(TStats(1, 80, 1, 1000),
            p,
            HUMAN,
            GROUND));
    }
  }
}
void Play::generate_mob()
{
  if (counter_ % 10 == 0)
  {
    Point p = portals_[rand() % portals_.size()];
    mobs_.push_back(std::make_shared<Mob>(p, MStats(10, 2, false)));
    mobs_[mobs_.size() - 1]->set_dir(p);
  }

  counter_++;
}

void Play::move_mobs()
{
  std::vector<unsigned int> mobs_to_remove;

  for (unsigned int i = 0; i < mobs_.size(); i++)
  {
    if (mobs_[i]->move())
    {
      if (mobs_[i]->get_pos() != nexus_)
        mobs_[i]->set_dir(map_.get_next(mobs_[i]->get_pos()));
      else
      {
        mobs_to_remove.push_back(i);
        mobs_[i]->set_stats(MStats(0, 0, false));
      }
    }
  }

  for (int i : mobs_to_remove)
    mobs_.erase(mobs_.begin() + i);
}

void Play::set_targets()
{
  for (auto& tower : towers_)
  {
    if (tower->is_target_reachable())
      continue;

    for (auto mob : mobs_)
    {
      Point mp = mob->get_pos();
      Point tp = tower->get_pos();
      Point d = mp - tp;

      if (d.get_manhattan() <= tower->get_real_stats().get_range())
      {
        tower->set_target(mob);
        break;
      }
    }
  }
}

void Play::attack()
{
  for (auto& tower : towers_)
  {
    std::shared_ptr<TAttack<Tower, Mob>> atk;
    atk = tower->attack();

    if (!atk)
      continue;

    *atk->get_target() += *atk;
  }
}

void Play::remove_deads()
{
  std::vector<unsigned int> mobs_to_remove;

  for (unsigned int i = 0; i < mobs_.size(); i++)
    if (mobs_[i]->get_stats().get_health() <= 0)
      mobs_to_remove.push_back(i);

  for (int i : mobs_to_remove)
  {
    gold_ += mobs_[i]->get_stats().get_gold();
    mobs_.erase(mobs_.begin() + i);
  }
}

void Play::update()
{
  generate_mob();
  move_mobs();
  set_targets();
  attack();
  remove_deads();
}

void Play::draw(sf::RenderWindow& window)
{
  map_.draw(window);

  for (auto mob : mobs_)
    mob->draw(window);

  for (auto tower : towers_)
    tower->draw(window);
}

long long unsigned Play::get_gold()
{
  return gold_;
}

std::shared_ptr<Tower> Play::get_select()
{
  return selected_;
}
