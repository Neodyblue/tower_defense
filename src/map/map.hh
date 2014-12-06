#ifndef MAP_HH
# define MAP_HH

# include <SFML/Graphics.hpp>

# include <vector>
# include <memory>

# include "type.hh"

class Map
{
    public:
        Map(int width, int height, int iter);
        ~Map();
        void draw(sf::RenderWindow& window);
        void gen_sprite();
        int get_width()
        {
            return width_;
        }
        int get_height()
        {
            return height_;
        }
        void get_color(Type t, sf::Uint8& r, sf::Uint8& g, sf::Uint8& b);
    private:
        std::vector<std::vector<Type>> map_;
        sf::Uint8* buf;
        int width_;
        int height_;
};

#endif /* MAP_HH */
