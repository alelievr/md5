#include "ft_retro.h"

EnemyShip::EnemyShip(void) : Ship("Enemy", 0, 0, 0, 0)
{

}

EnemyShip::EnemyShip(std::string name, int x, int y, int hp, int maxhp) : Ship(name, x, y, hp, maxhp)
{
	this->direction = -1;
	std::cout << "Enemy ship created on " << x << "/" << y << std::endl;
}

EnemyShip::~EnemyShip(void)
{
	std::cout << "Enemy ship destroyed" << std::endl;
}

void	EnemyShip::fire(void)
{
	
}

void	EnemyShip::die(void)
{
	
}

void	EnemyShip::move(int x, int y)
{
	std::cout << "EnemyShip moves at " << x << "/" << y << std::endl;
}
