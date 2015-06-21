#include "Ship.class.hpp"
#include "PlayerShip.class.hpp"
#include "ft_retro.hpp"

PlayerShip::PlayerShip(void)
{
	PlayerShip("player", 10, 10, 10, 10);
}

PlayerShip::PlayerShip(std::string name, int x, int y, int  hp , int maxhp) : Ship(name, x, y, hp, maxhp)
{
	this->setMask(MASK_SHIP_LOW);
	this->direction = 1;
	this->_life = 5;
	this->_isDead = false;
	this->moveTimer = 0;
	this->fireTimer = 0;
	this->setDam(100);
	//std::cout << "playership constructed : " << std::endl<< this->data << std::endl;
}

PlayerShip &	PlayerShip::operator=(PlayerShip const & src)
{
	if (this != &src)
	{
		this->setName(src.getName());
		this->setX(src.getX());
		this->setY(src.getY());
		this->setHP(src.getHP());
		this->setMHP(src.getMHP());
		this->setMask(src.getMask());
		this->_life = src.getLife();
		this->_isDead = !src.isAlive();
		this->setDam(src.getDam());
		this->moveTimer = 0;
		this->fireTimer = 0;
	}
	return (*this);
}

PlayerShip::PlayerShip(PlayerShip const & src)
{
	*this = src;
}

int			PlayerShip::getLife(void) const
{
	return (this->_life);
}

void		PlayerShip::fire(void)
{
	playSound(SOUND_LASER);
	this->fireTimer = clock() + INTER_FIRE_ENEMY + (rand() % 10000);
}

void		PlayerShip::move(void) { }

void		PlayerShip::move(int key)
{
	if (key == KEY_TOP)
		this->setY(this->getY() + 1);
	if (key == KEY_BOT)
		this->setY(this->getY() - 1);
	if (key == 68)
		this->setX(this->getX() - 1);
	if (key == 67)
		this->setX(this->getX() + 1);
	if (key == KEY_FIRE)
		this->fire();
	(void)key;
}

void		PlayerShip::die(void)
{
	playSound(SOUND_EXPLOSION);
	this->_life--;
	if (this->_life < 0)
		this->_isDead = true;
	this->setHP(this->getMHP());
}

bool		PlayerShip::isAlive(void) const
{
	return (!this->_isDead);
}

PlayerShip::~PlayerShip(void)
{
//	std::cout << "PlayerShip destroyed !" << std::endl;
}
