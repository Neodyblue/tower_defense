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

  int get_health() const;
  int get_speed() const;
  bool is_flying() const;
  int get_gold() const;

private:
  int health_;
  int speed_;
  bool fly_;
  int gold_;
};

#endif /* end of include guard: MOB_STATS_HH */
