#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP

class		EnemyShip : Ship
{
	private:
		int		_index;

	public:
		EnemyShip(std::string name, int x, int y, int hp, int mhp);
		~EnemyShip(void);

		EnemyShip *	next;
		EnemyShip *	prev;

		void		fire(void);
		void		die(void);
		void		move(int x, int y);

		int			getIndex(void);
		void		setIndex(int i);
};

#endif
