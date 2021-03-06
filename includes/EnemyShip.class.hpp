#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP
# include "Ship.class.hpp"

class		EnemyShip : public Ship
{
	private:
		EnemyShip* _next;
		EnemyShip* _prev;

	public:
		EnemyShip(void);
		EnemyShip(std::string name, int x, int y, int hp, int mhp);
		virtual ~EnemyShip(void);

		EnemyShip *	next;
		EnemyShip *	prev;

		void		fire(void);
		void		die(void);
		void		move(void);
		EnemyShip*  getNext(void) const;
		void		setNext(EnemyShip*);
		void		nextPosition(void);

		EnemyShip*   getPrev(void) const;
		void    setPrev(EnemyShip*);

		void    append(EnemyShip*);
};

#endif
