#include <ctime>
#include <cstdlib>

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
}

void Map::draw(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(1, 1));
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
        {
            rectangle.setPosition(x * 1, y * 1);
            if (map_[x][y] == Type::PROFONDSEA)
                rectangle.setFillColor(sf::Color(0x32, 0x5d, 0xe0));
            else if (map_[x][y] == Type::SEA)
                rectangle.setFillColor(sf::Color(0x32, 0x5d, 0xe0));
            else if (map_[x][y] == Type::BEACH)
                rectangle.setFillColor(sf::Color(0xAd,0xd2, 0x47));
            else if (map_[x][y] == Type::PLAIN)
                rectangle.setFillColor(sf::Color(0x02, 0x7d, 0x01));
            else if (map_[x][y] == Type::FOREST)
                rectangle.setFillColor(sf::Color(0x00, 0x50, 0x00));
            else if (map_[x][y] == Type::PROFONDFOREST)
                rectangle.setFillColor(sf::Color(0x01, 0x3a, 0x03));
            else if (map_[x][y] == Type::MOUNTAIN)
                rectangle.setFillColor(sf::Color(0x6a, 0x38, 0x05));
            else
                rectangle.setFillColor(sf::Color(0x60, 0x2e, 0x00));
            window.draw(rectangle);
        }
}
