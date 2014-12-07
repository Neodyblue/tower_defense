#ifndef PLAY_HH
# define PLAY_HH

# include <SFML/Graphics.hpp>

# include <vector>
# include <memory>

# include "map/map.hh"
# include "mob/mob.hh"
# include "tower/tower.hh"

class Play
{
  public:
    Play();
    void update();
    void draw(sf::RenderWindow& window);

  private:
    void generate_mob();
    void move_mobs();
    void set_targets();
    void attack();
    void remove_deads();
    Map map_;
    std::vector<std::shared_ptr<Mob>> mobs_;
    std::vector<std::shared_ptr<Tower>> towers_;
    std::vector<Point> portals_;
    Point nexus_;

    int counter_;
};

#endif /* !PLAY_HH */
