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

  int get_damages() const;
  int get_range() const;
  int get_radius() const;
  int get_cooldown() const;

private:
  int damages_;
  int range_;
  int radius_;
  int cooldown_;
};

#endif /* end of include guard: TOWER_STATS_HH */
