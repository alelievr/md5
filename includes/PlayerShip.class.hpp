#ifndef PLAYERSHIP_HPP
# define PLAYERSHIP_HPP
# include "Ship.class.hpp"

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

		PlayerShip(void);
		PlayerShip(std::string name, int x, int y, int hp, int maxhp);
		PlayerShip(PlayerShip const & src);
		~PlayerShip(void);

		PlayerShip &	operator=(PlayerShip const & src);

		void		fire(void);
		void		die(void);
		void		move(void);
		void		move(int key);
		int			getLife(void) const;
		bool		isAlive(void) const;
};

#endif
