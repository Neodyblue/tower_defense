#ifndef POINT_HH
# define POINT_HH

class Point
{
public:
  Point(int x = 0, int y = 0);

  Point& operator+=(Point& other);
  Point& operator+(Point& other);
  Point& operator-=(Point& other);
  Point& operator-(Point& other);

private:
  int x_;
  int y_;
};

#endif /* end of include guard: POINT_HH */
