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
    buf = new sf::Uint8[width_ * height_ * 4];
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
        {
            sf::Uint8& r = buf[(x + y * width_) * 4];
            sf::Uint8& g = buf[(x + y * width_) * 4 + 1];
            sf::Uint8& b = buf[(x + y * width_) * 4 + 2];
            get_color(map_[x][y], r, g, b);
            buf[(x + y * width_) * 4 + 3] = 255;
        }
}

Map::~Map()
{
    delete[] buf;
}

void Map::draw(sf::RenderWindow& window)
{
    sf::Texture texture;
    texture.create(width_, height_);
    sf::Sprite sprite_ = sf::Sprite(texture);
    texture.update(buf);
    window.draw(sprite_);
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
