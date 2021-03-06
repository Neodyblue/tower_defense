#ifndef PLAY_HH
# define PLAY_HH

# include <SFML/Graphics.hpp>

# include <vector>
# include <memory>

# include "map/map.hh"
# include "mob/mob.hh"
# include "tower/tower.hh"
# include "wave/wave.hh"

class Play
{
  public:
    Play();
    void reset();
    void update();
    void input(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window, sf::Font& f);
    int get_life();
    int get_score();

  private:
    void generate_mob();
    void move_mobs();
    void set_targets();
    void attack();
    void remove_deads();
    void add_tower_(Point p, tower_type t);

    Map map_;
    std::vector<std::shared_ptr<Mob>> mobs_;
    std::vector<std::shared_ptr<Tower>> towers_;
    std::vector<Point> portals_;
    Point nexus_;
    int selected_tower_ = 0;

    int farme_ = 0;
    int churche_ = 0;
    long long unsigned gold_ = 100;
    int nexus_life_ = 255;
    bool nexus_touched_ = false;
    int counter_;
    int refresh_mob_ = 15;
    int level_;
    int score_;
    Wave current_wave_;
};

#endif /* !PLAY_HH */
