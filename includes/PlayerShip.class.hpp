#ifndef PLAYERSHIP_HPP
# define PLAYERSHIP_HPP
# include "ft_retro.h"

class		PlayerShip : public Ship
{
	private:
		int		_life;
		bool	_isDead;

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
		int			getLife(void);
		bool		isAlive(void);
};

#endif
