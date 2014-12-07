#include <iostream>

#include "play/play.hh"

Play::Play()
  : map_(5, 5, 7)
  , counter_(0)
{
  portals_ = map_.get_portals();
  nexus_ = map_.and_get();
  towers_.push_back(std::make_shared<Tower>(TStats(1, 80, 1, 1000),
                    Point(nexus_.get_x() + 10, nexus_.get_y() + 10),
                    HUMAN,
                    GROUND));
}

void Play::generate_mob()
{
  if (counter_ % 60 == 0)
  {
    Point p = portals_[rand() % portals_.size()];
    mobs_.push_back(std::make_shared<Mob>(p, MStats(1, 1, false)));
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
    mobs_.erase(mobs_.begin() + i);
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
