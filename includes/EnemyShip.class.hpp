#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP

class		EnemyShip : public Ship
{
	private:

	public:
		EnemyShip(void);
		EnemyShip(std::string name, int x, int y, int hp, int mhp);
		~EnemyShip(void);

		EnemyShip *	next;
		EnemyShip *	prev;

		void		fire(void);
		void		die(void);
		void		move(int x, int y);
};

#endif
