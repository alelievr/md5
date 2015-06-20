#ifndef OBSTACLE_CLASS_HPP
# define OBSTACLE_CLASS_HPP

class	Obstacle : Ship
{
	private:
		int		_index;

	public:
		Obstacle(int x, int y);
		~Obstacle(void);

		Obstacle *	next;
		Obstacle *	prev;

		void		fire(void);
		void		die(void);
		void		move(int x, int y);

		int			getIndex(void);
		void		setIndex(int i);
};

#endif
