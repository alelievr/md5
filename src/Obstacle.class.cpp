#include "ft_retro.h"

Obstacle::Obstacle(int x, int y) : Ship("Asteroid", x, y, 500000, 500000)
{
	std::cout << "new ostacle in " << x << "/" << y << std::endl;
}

Obstacle::~Obstacle(void)
{
	std::cout << "Destructed Asteroid" << std::endl;
}

void		Obstacle::fire(void) { }

void		Obstacle::die(void) { }

void		Obstacle::move(int x, int y) { (void)x; (void)y; }

int			Obstacle::getIndex(void)
{
	return (this->_index);
}

void		Obstacle::setIndex(int i)
{
	this->_index = i;
}
