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

bool Point::operator==(Point& other)
{
  return x_ == other.x_ && y_ == other.y_;
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
