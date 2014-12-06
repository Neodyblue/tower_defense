#ifndef MAP_HH
# define MAP_HH

# define CASE_SIZE 10

# include <SFML/Graphics.hpp>

# include <tuple>
# include <vector>
# include <memory>

# include "type.hh"
# include "../../include/point.hh"

class Map
{
  public:
    Map(int width, int height, int iter);
    ~Map();

    void draw(sf::RenderWindow& window);
    void get_color(Type t, sf::Uint8& r, sf::Uint8& g, sf::Uint8& b);

    int get_width_pixel() const;
    int get_height_pixel() const;

    int get_width_case() const;
    int get_height_case() const;

    Type get_case(int x, int y) const;
  private:
    void gen_case_map_();
    void gen_path_();

    void gen_sprite_();
    void gen_case_sprite_();
    void gen_case_spec();

    std::vector<std::vector<Type>> map_;
    std::vector<std::vector<Type>> case_;
    sf::Uint8* buf_;

    Point p;
    int width_;
    int height_;
};

#endif /* MAP_HH */
