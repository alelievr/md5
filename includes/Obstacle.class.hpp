#ifndef OBSTACLE_CLASS_HPP
# define OBSTACLE_CLASS_HPP

class	Obstacle : public Ship
{
	private:

	public:
		Obstacle(void);
		Obstacle(int x, int y);
		~Obstacle(void);

		Obstacle *	next;
		Obstacle *	prev;

		void		fire(void);
		void		die(void);
		void		move(int x, int y);
};

#endif
