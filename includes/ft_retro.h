#ifndef FT_RETRO_H
# define FT_RETRO_H

# define BIT_ON(x, y) (x = x | (1 << y))
# define BIT_OFF(x, y) (x &= ~(1 << y))
# define BIT_TEST(x, y) (((x & (1 << y)) == 0) ? 0 : 1)

# include <iostream>
# include <string>
# include "Ship.class.hpp"
# include "PlayerShip.class.hpp"
# include "EnemyShip.class.hpp"
# include "Obstacle.class.hpp"
# include "GameStatus.class.hpp"

std::string		sgetl(std::string s);

#endif