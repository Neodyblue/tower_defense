#include <iostream>

#include "tower/tower.hh"

int main()
{
  auto tptr = std::make_shared<Tower>(TStats(10, 3, 3, 1000),
      Point(0,0), HUMAN, GROUND);
  auto mptr = std::make_shared<Mob>(Point(1, 1), MStats(100, 1, false));

  std::shared_ptr<TAttack<Tower, Mob>> atk;
  std::cout << "Incoming mob with " << mptr->get_stats().get_health() << "PV"
            << std::endl;
  tptr->set_target(mptr);

  while (true)
  {
    while (!(atk = tptr->attack()));
    std::cout << "ATTAQUE !" << std::endl;
    *mptr += *atk;
    if (mptr->get_stats().get_health() <= 0)
      break;
    std::cout << atk->get_target()->get_stats().get_health() << std::endl;
  }

  return 0;
}
