#include "ft_retro.h"

Obstacle::Obstacle(void)
{
	this->setDisplay(false);
	Obstacle(0, 0);
}

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
