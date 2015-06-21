#include "ft_retro.h" 

PlayerShip::PlayerShip(std::string name, int x, int y, int  hp , int maxhp) : Ship(name, x, y, hp, maxhp)
{
	this->setMask(MASK_SHIP_LOW);
	this->direction = 1;
	std::cout << "playership constructed : " << std::endl<< this->data << std::endl;
}

void		PlayerShip::fire(void)
{
	
}

void		PlayerShip::die(void)
{
	
}

void		PlayerShip::move(int x, int y)
{
	this->setX(x);
	this->setY(y);
	std::cout << "Playership moved at " << x << "/" << y << std::endl;
}

PlayerShip::~PlayerShip(void)
{
	std::cout << "PlayerShip destroyed !" << std::endl;
}
