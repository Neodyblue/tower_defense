#include <cmath>

#include "point.hh"

Point::Point(int x, int y)
  : x_(x)
  , y_(y)
{}

Point& Point::operator+=(Point& other)
{
  return *this + other;
}

Point& Point::operator+(Point& other)
{
  x_ += other.x_;
  y_ += other.y_;

  return *this;
}

Point& Point::operator-=(Point& other)
{
  return *this - other;
}

Point& Point::operator-(Point& other)
{
  x_ -= other.x_;
  y_ -= other.y_;

  return *this;
}

int Point::get_manhattan()
{
  return std::abs(x_) + std::abs(y_);
}

bool operator==(Point p1, Point p2)
{
  return p1.get_x() == p2.get_x() && p1.get_y() == p2.get_y();
}
bool operator!=(Point p1, Point p2)
{
  return !(p1 == p2);
}
