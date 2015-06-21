#ifndef PLAYERSHIP_HPP
# define PLAYERSHIP_HPP
# include "Ship.class.hpp"

class		PlayerShip : public Ship
{
	public:
		enum	e_keys {
			FORWARD = 0,
			BACK = 1,
			LEFT = 2,
			RIGHT = 3,
			FIRE = 4,
			PAUSE = 30,
			ESC = 31
		};
		int		keys;

		PlayerShip(std::string name, int x, int y, int hp, int maxhp);
		~PlayerShip(void);

		void		fire(void);
		void		die(void);
		void		move(int x, int y);
};

#endif
