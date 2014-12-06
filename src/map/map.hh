#ifndef MAP_HH
# define MAP_HH

# include <SFML/Graphics.hpp>
# include <vector>
# include "type.hh"

class Map
{
    public:
        Map(int width, int height, int iter);
        void draw(sf::RenderWindow& window);
        int get_width()
        {
            return width_;
        }
        int get_height()
        {
            return height_;
        }
    private:
        std::vector<std::vector<Type>> map_;
        int width_;
        int height_;
};

#endif /* MAP_HH */
