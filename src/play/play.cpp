#include <iostream>

#include "play/play.hh"

Play::Play()
  : map_(5, 5, 7)
{
  portals_ = map_.get_portals();
  nexus_ = map_.and_get();
}

void Play::update()
{
  if (counter % 60 == 0)
  {
    Point p = portals_[rand() % portals_.size()];
    mobs_.push_back(std::make_shared<Mob>(p, MStats(1, 1, false)));
    mobs_[mobs_.size() - 1]->set_dir(p);
  }
  counter++;
  for (auto mob : mobs_)
  {
    if (mob->move())
      if (mob->get_pos() != nexus_)
        mob->set_dir(map_.get_next(mob->get_pos()));
  }
}

void Play::draw(sf::RenderWindow& window)
{
  map_.draw(window);
  for (auto mob : mobs_)
    mob->draw(window);
}
