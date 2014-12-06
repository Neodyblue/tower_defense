#include <iostream>

#include "play/play.hh"

Play::Play()
  : map_(5, 5, 7)
  , counter_(0)
{
  portals_ = map_.get_portals();
  nexus_ = map_.and_get();
}

void Play::generate_mob()
{
  if (counter_ % 60 == 0)
  {
    Point p = portals_[rand() % portals_.size()];
    mobs_.push_back(std::make_shared<Mob>(p, MStats(1, rand() % 9 + 1, false)));
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
        mobs_to_remove.push_back(i);
    }
  }

  for (int i : mobs_to_remove)
    mobs_.erase(mobs_.begin() + i);
}

void Play::update()
{
  generate_mob();
  move_mobs();
}

void Play::draw(sf::RenderWindow& window)
{
  map_.draw(window);

  for (auto mob : mobs_)
    mob->draw(window);
}
