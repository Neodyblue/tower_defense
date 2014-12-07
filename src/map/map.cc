#include <ctime>
#include <cstdlib>
#include <iostream>

#include "map/map.hh"
#include "map/gen.hh"

Map::Map(int width, int height, int iter)
{
  srand(time(NULL));
  auto v = Gen::Generate(width, height, iter);
  width_ = v->size();
  height_ = (*v)[0].size();
  map_.resize(v->size());
  for (int x = 0; x < width_; x++)
  {
    map_[x].resize(height_);
    for (int y = 0; y < height_; y++)
    {
      if ((*v)[x][y] > 230)
        map_[x][y] = Type::PROFONDSEA;
      else if ((*v)[x][y] > 200)
        map_[x][y] = Type::SEA;
      else if ((*v)[x][y] > 90)
        map_[x][y] = Type::PLAIN;
      else if ((*v)[x][y] > 50)
        map_[x][y] = Type::MOUNTAIN;
      else
        map_[x][y] = Type::HIGHMOUNTAIN;
    }
  }
  v = Gen::Generate(width, height, iter);
  for (int x = 0; x < width_; x++)
  {
    for (int y = 0; y < height_; y++)
    {
      if (map_[x][y] == Type::BEACH && (*v)[x][y] > 200)
        map_[x][y] = Type::FOREST;
      else if (map_[x][y] != Type::PLAIN)
        continue;
      if ((*v)[x][y] > 200)
        map_[x][y] = Type::PROFONDFOREST;
      else if ((*v)[x][y] > 150)
        map_[x][y] = Type::FOREST;
    }
  }
  buf_ = nullptr;
  gen_case_map_();
  gen_path_();
  gen_sprite_();
}

Map::~Map()
{
  delete[] buf_;
}

void Map::gen_case_map_()
{
  case_.resize(get_width_case());
  for (int x = 0; x < get_width_case(); x++)
  {
    case_[x].resize(get_height_case());
    for (int y = 0; y < get_height_case(); y++)
    {
      case_[x][y] =
        map_[x * CASE_SIZE + CASE_SIZE / 2][y * CASE_SIZE + CASE_SIZE / 2];
    }
  }
}

void Map::gen_portal_(int nop)
{
  int old = -1;
  int kind;
  Point p;
  for (int i = 0; i < 100; i++)
  {
    while (old == (kind = random() % 4))
      continue;
    if (kind == 0 && old != 1 && nop != 1)
      p = Point(1, 0);
    else if (kind == 1 && old != 0 && nop != 0)
      p = Point(-1, 0);
    else if (kind == 2 && old != 3 && nop != 3)
      p = Point(0, 1);
    else if (kind == 3 && old != 2 && nop != 2)
      p = Point(0, -1);
    else
      continue;
    old = kind;
    for (int k = 0; k < 3 + rand() % 15; k++)
    {
      Point n = portals_[nop].path[portals_[nop].path.size() - 1];
      n += p;
      if (Type::NONE <= get_case(n.get_x(), n.get_y()))
        break;
      portals_[nop].path.push_back(n);
      case_[n.get_x()][n.get_y()] = Type::ROAD;
    }
    Point n = portals_[nop].path[portals_[nop].path.size() - 1];
    n += p;
    if (Type::NONE == get_case(n.get_x(), n.get_y()))
      break;
  }
}

void Map::gen_path_()
{
  int x = get_width_case() / 2;
  int y = get_height_case() / 2;
  x += rand() % 20 - 10;
  y += rand() % 20 - 10;
  nexus_ = Point(x, y);

  Point p;
  for (int i = 0; i < 4; i++)
  {
    portals_.push_back(Portal());
    portals_[i].path.push_back(nexus_);
    if (i == 0)
      p = Point(1, 0);
    else if (i == 1)
      p = Point(-1, 0);
    else if (i == 2)
      p = Point(0, 1);
    else if (i == 3)
      p = Point(0, -1);
    for (int k = 0; k < 6; k++)
    {
      Point n = portals_[i].path[portals_[i].path.size() - 1];
      n += p;
      if (Type::NONE <= get_case(n.get_x(), n.get_y()))
        break;
      portals_[i].path.push_back(n);
      case_[n.get_x()][n.get_y()] = Type::ROAD;
    }
    gen_portal_(i);
  }
}

void Map::gen_case_sprite_()
{
  delete[] buf_;
  buf_ = new sf::Uint8[width_ * height_ * 4];
  for (int x = 0; x < width_; x++)
    for (int y = 0; y < height_; y++)
    {
      int x_aux = x / CASE_SIZE;
      int y_aux = y / CASE_SIZE;
      sf::Uint8& r = buf_[(x + y * width_) * 4];
      sf::Uint8& g = buf_[(x + y * width_) * 4 + 1];
      sf::Uint8& b = buf_[(x + y * width_) * 4 + 2];
      get_color(case_[x_aux][y_aux], r, g, b);
      buf_[(x + y * width_) * 4 + 3] = 255;
      if (x % CASE_SIZE == 0 || y % CASE_SIZE == 0)
      {
        r -= r < 10 ? r : 10;
        g -= g < 10 ? g : 10;
        b -= b < 10 ? b : 10;
      }
    }
}

void Map::gen_sprite_()
{
  delete[] buf_;
  buf_ = new sf::Uint8[width_ * height_ * 4];
  for (int x = 0; x < width_; x++)
    for (int y = 0; y < height_; y++)
    {
      sf::Uint8& r = buf_[(x + y * width_) * 4];
      sf::Uint8& g = buf_[(x + y * width_) * 4 + 1];
      sf::Uint8& b = buf_[(x + y * width_) * 4 + 2];
      get_color(map_[x][y], r, g, b);
      buf_[(x + y * width_) * 4 + 3] = 255;
      if (x % CASE_SIZE == 0 || y % CASE_SIZE == 0)
      {
        r -= r < 10 ? r : 10;
        g -= g < 10 ? g : 10;
        b -= b < 10 ? b : 10;
      }
    }
}


void Map::draw(sf::RenderWindow& window)
{
  sf::Texture texture;
  texture.create(width_, height_);
  sf::Sprite sprite_ = sf::Sprite(texture);
  texture.update(buf_);
  window.draw(sprite_);

  /*Draw Nexus*/
  sf::RectangleShape rectangle(sf::Vector2f(CASE_SIZE, CASE_SIZE));
  sf::Color c = sf::Color::Black;
  c.a = 100;
  rectangle.setFillColor(c);
  /*Draw path*/
  for (unsigned i = 0; i < portals_.size(); i++)
    for (unsigned j = 0; j < portals_[i].path.size(); j++)
    {
      rectangle.setPosition(CASE_SIZE * portals_[i].path[j].get_x(),
                            CASE_SIZE * portals_[i].path[j].get_y());
      window.draw(rectangle);
    }
  rectangle.setPosition(CASE_SIZE * nexus_.get_x(),
                        CASE_SIZE * nexus_.get_y());
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineThickness(-1);
  rectangle.setOutlineColor(sf::Color(200, 200, 200));
  window.draw(rectangle);

}

Type Map::get_case(int x, int y) const
{
  if (x < 0 || y < 0 || x >= get_width_case() || y >= get_height_case())
    return Type::NONE;
  return case_[x][y];
}

int Map::get_width_case() const
{
  return width_ / CASE_SIZE;
}

int Map::get_height_case() const
{
  return height_ / CASE_SIZE;
}

int Map::get_width_pixel() const
{
  return width_;
}

int Map::get_height_pixel() const
{
  return height_;
}

bool Map::can_build(Point& p, tower_type t)
{
  Type type = get_case(p.get_x() / CASE_SIZE, p.get_y() / CASE_SIZE);
  if (type >= Type::NONE)
    return 0;
  if (t == HUMAN)
    return 0 != (type & Type::BEACH);
  if (t == MOUNTAIN)
    return 0 != (type & Type::MOUNTAIN);
  if (t == WATER)
    return 0 != (type & Type::SEA);
  if (t == WOOD)
    return 0 != (type & Type::FOREST);
  else
    return 0;
}

Point Map::get_build_position(Point& p)
{
  case_[p.get_x() / CASE_SIZE][p.get_y() / CASE_SIZE] = Type::TOWER;
  return Point(p.get_x() - (p.get_x() % CASE_SIZE) - CASE_SIZE / 2,
               p.get_y() - (p.get_y() % CASE_SIZE) - CASE_SIZE / 2);
}

Point Map::and_get()
{
  return Point(nexus_.get_x() * CASE_SIZE + CASE_SIZE / 2,
               nexus_.get_y() * CASE_SIZE + CASE_SIZE / 2);
}

Point Map::get_next(Point p)
{
  Point current(p.get_x() / CASE_SIZE, p.get_y() / CASE_SIZE);
  Point next(0, 0);
  for (unsigned i = 0; i < portals_.size(); i++)
    for (unsigned j = 0; j < portals_[i].path.size(); j++)
      if (portals_[i].path[j] == current)
      {
        if (j == 0)
          next = portals_[i].path[j];
        else
          next = portals_[i].path[j - 1];
        break;
      }
  return Point(next.get_x() * CASE_SIZE + CASE_SIZE / 2,
               next.get_y() * CASE_SIZE + CASE_SIZE / 2);
}

std::vector<Point> Map::get_portals()
{
  std::vector<Point> res;
  for (unsigned i = 0; i < portals_.size(); i++)
  {
    Point p = portals_[i].path[portals_[i].path.size() - 1];
    p.set_x(p.get_x() * CASE_SIZE + CASE_SIZE / 2);
    p.set_y(p.get_y() * CASE_SIZE + CASE_SIZE / 2);
    res.push_back(p);
  }
  return res;
}

void Map::get_color(Type t, sf::Uint8& r, sf::Uint8& g, sf::Uint8& b)
{
  if (t == Type::PROFONDSEA)
  {
    r = 0x32;
    g = 0x5d;
    b = 0xe0;
  }
  else if (t == Type::SEA)
  {
    r = 0x32;
    g = 0x5d;
    b = 0xe0;
  }
  else if (t == Type::BEACH)
  {
    r = 0xad;
    g = 0xd2;
    b = 0x47;
  }
  else if (t == Type::PLAIN)
  {
    r = 0x02;
    g = 0x7d;
    b = 0x01;
  }
  else if (t == Type::FOREST)
  {
    r = 0x00;
    g = 0x50;
    b = 0x00;
  }
  else if (t == Type::PROFONDFOREST)
  {
    r = 0x01;
    g = 0x3a;
    b = 0x03;
  }
  else if (t == Type::MOUNTAIN)
  {
    r = 0x6a;
    g = 0x38;
    b = 0x05;
  }
  else if (t == Type::HIGHMOUNTAIN)
  {
    r = 0x60;
    g = 0x2e;
    b = 0x00;
  }
}
