#ifndef MOB_STATS_HH
# define MOB_STATS_HH

class MStats
{
public:
  MStats(int health, int speed, bool fly);

  MStats& operator+=(MStats& other);
  MStats& operator+(MStats& other);
  MStats& operator-=(MStats& other);
  MStats& operator-(MStats& other);

private:
  int health_;
  int speed_;
  bool fly_;
};

#endif /* end of include guard: MOB_STATS_HH */
