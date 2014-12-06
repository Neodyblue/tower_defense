#ifndef TOWER_STATS_HH
# define TOWER_STATS_HH

class TStats
{
public:
  TStats(int damages, int range, int radius, int cooldown);

  TStats& operator+=(TStats& other);
  TStats& operator+(TStats& other);
  TStats& operator-=(TStats& other);
  TStats& operator-(TStats& other);

private:
  int damages_;
  int range_;
  int radius_;
  int cooldown_;
};

#endif /* end of include guard: TOWER_STATS_HH */
