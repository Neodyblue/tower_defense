#include <ctime>
#include <cstdlib>
#include <iostream>

#include "map.hh"
#include "gen.hh"

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
  gen_sprite_();
}

Map::~Map()
{
  delete[] buf_;
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

void Map::draw(sf::RenderWindow& window)
{
  sf::Texture texture;
  texture.create(width_, height_);
  sf::Sprite sprite_ = sf::Sprite(texture);
  texture.update(buf_);
  window.draw(sprite_);
}

Type Map::get_case(int x, int y) const
{
  if (x < 0 && y < 0 && x > get_width_case() && y > get_height_case())
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
  else
  {
    r = 0x60;
    g = 0x2e;
    b = 0x00;
  }
}
