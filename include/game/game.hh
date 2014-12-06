#ifndef GAME_HH_
# define GAME_HH_

# include <vector>
# include <map>
# include <memory>

# include "game/menu.hh"
# include "mob/mob.hh"
# include "tower/tower.hh"

class Game
{
public:
  Game();
  void add_mob(std::shared_ptr<Mob>);
  void delete_mob(std::shared_ptr<Mob>);

  void add_tower(std::shared_ptr<Tower>);
  void delete_tower(std::shared_ptr<Tower>);

  void add_attack(std::shared_ptr<Attack>);
  void delete_attack(std::shared_ptr<Attack>);

  void update(); /* LOL!! */

  virtual ~Game();

private:
  std::map<std::shared_ptr<Mob>> mobs_;
  std::map<std::shared_ptr<Tower>> towers_;
  std::map<std::shared_ptr<Attack>>
  std::map<std::shared_ptr<Menu>> menus_;
  std::shared_ptr<Menu> current_menu_;

  std::shared_ptr<Map> map_;

  bool carrying_;
  unsigned int gold;
  unsigned int faith;
};

#endif /* !GAME_HH_ */
