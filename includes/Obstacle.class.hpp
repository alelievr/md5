#ifndef OBSTACLE_CLASS_HPP
# define OBSTACLE_CLASS_HPP
# include "Ship.class.hpp"

class	Obstacle : public Ship
{
	private:
		Obstacle* _next;
		Obstacle* _prev;

	public:
		Obstacle(void);
		Obstacle(int x, int y);
		~Obstacle(void);

		Obstacle *	next;
		Obstacle *	prev;

		void		fire(void);
		void		die(void);
		void		move(int x, int y);

		Obstacle*   getNext(void) const;
		void    setNext(Obstacle*);

		Obstacle*   getPrev(void) const;
		void    setPrev(Obstacle*);

		void    append(Obstacle*);
};

#endif
