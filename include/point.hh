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

  int get_x()
  {
    return x_;
  }

  int get_y()
  {
    return y_;
  }

  void set_x(int x)
  {
    x_ = x;
  }

  void set_y(int y)
  {
    y_ = y;
  }

  int get_manhattan();

private:
  int x_;
  int y_;
};

bool operator==(Point p1, Point p2);
bool operator!=(Point p1, Point p2);

#endif /* end of include guard: POINT_HH */
