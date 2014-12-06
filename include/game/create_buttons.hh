#ifndef CREATE_BUTTONS_HH_
# define CREATE_BUTTONS_HH_

# include <SFML/Graphics.hpp>
# include <memory>
# include "game/button.hh"

std::vector<std::shared_ptr<Button>> add_begin_buttons(sf::Font& f,
                                                       sf::Vector2u win_size);


std::vector<std::shared_ptr<Button>> add_pause_buttons(sf::Font& f,
                                                       sf::Vector2u win_size);

std::vector<std::shared_ptr<Button>> add_game_buttons(sf::Font& f,
                                                      sf::Vector2u win_size);

std::vector<std::shared_ptr<Button>> add_over_buttons(sf::Font& f,
                                                      sf::Vector2u win_size);


#endif /* !CREATE_BUTTONS_HH_ */
