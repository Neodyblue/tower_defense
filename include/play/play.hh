#ifndef PLAY_HH
# define PLAY_HH

# include <SFML/Graphics.hpp>

# include <vector>
# include <memory>

# include "map/map.hh"
# include "mob/mob.hh"

class Play
{
  public:
    Play();
    void update();
    void draw(sf::RenderWindow& window);
  private:
    Map map_;
    std::vector<std::shared_ptr<Mob>> mobs_;
    std::vector<Point> portals_;
    std::vector<Tower> towers_;
    Point nexus_;

    int counter = 0;
};

#endif /* !PLAY_HH */
