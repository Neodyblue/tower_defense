#ifndef WAVE_HH
# define WAVE_HH

# include <memory>

# include "mob/mob.hh"

class Wave
{
public:
  Wave(float pgob, float pmin, float ptro, float pske,
       float pmur, unsigned long long mobs);

  std::shared_ptr<Mob> generate(Point p);

private:
  float p_gob_;
  float p_min_;
  float p_tro_;
  float p_ske_;
  float p_mur_;
  unsigned long long max_mobs_;
};

#endif /* end of include guard: WAVE_HH */
