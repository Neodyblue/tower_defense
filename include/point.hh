#ifndef POINT_HH
# define POINT_HH

class Point
{
public:
  Point(int x = 0, int y = 0);

  Point& operator+=(Point& other);
  bool operator==(Point& other);
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

  int get_manhattan();

private:
  int x_;
  int y_;
};

#endif /* end of include guard: POINT_HH */
