#include "wave/wave.hh"
#include <cstdlib>

Wave::Wave(float pgob, float pmin, float ptro, float pske,
     float pmur, unsigned long long mobs)
  : p_gob_(pgob)
  , p_min_(pmin)
  , p_tro_(ptro)
  , p_ske_(pske)
  , p_mur_(pmur)
  , max_mobs_(mobs)
{}

std::shared_ptr<Mob> Wave::generate(Point p)
{
  if (!max_mobs_)
    return std::shared_ptr<Mob>{};

  float max = (rand() % 100) * p_gob_, temp = 0;
  mob_type m = GOBLIN;

  if ((temp = (rand() % 100) * p_min_) > max)
    m = MINION;

  if ((temp = (rand() % 100) * p_tro_) > max)
    m = TROLL;

  if ((temp = (rand() % 100) * p_ske_) > max)
    m = SKELETON;

  if ((temp = (rand() % 100) * p_mur_) > max)
    m = MURLOC;

  max_mobs_--;
  switch (m)
    {
    case GOBLIN:
      return Mob::get_goblin(p);
    case MINION:
      return Mob::get_minion(p);
    case TROLL:
      return Mob::get_troll(p);
    case SKELETON:
      return Mob::get_skeleton(p);
    case MURLOC:
      return Mob::get_murloc(p);
    }
}
