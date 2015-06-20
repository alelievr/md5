#include "ft_retro.h"

EnemyShip::EnemyShip(void) : Ship("Enemy", 0, 0, 0, 0)
{

}

EnemyShip::EnemyShip(std::string name, int x, int y, int hp, int maxhp) : Ship(name, x, y, hp, maxhp)
{
	this->setNext(NULL);
	this->setPrev(NULL);
	this->direction = -1;
	std::cout << "Enemy ship created on " << x << "/" << y << std::endl;
}

EnemyShip::~EnemyShip(void)
{
	std::cout << "Enemy ship destroyed" << std::endl;
	if (this->getPrev() != NULL)
		this->setPrev(this->getNext());
	if (this->getNext() != NULL)
		this->setNext(this->getNext());
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
void EnemyShip::append( EnemyShip* newEnemyShip ) {
	if (this->getNext() == NULL) {
		this->setNext(newEnemyShip);
		this->getNext()->setPrev(this);
		std::cout << "Appened to list" << std::endl;
	} else
		this->getNext()->append(newEnemyShip);
}

EnemyShip*   EnemyShip::getNext( void ) const {
	return this->_next;
}

void    EnemyShip::setNext( EnemyShip* s ) {
	this->_next = s;
}

EnemyShip*   EnemyShip::getPrev( void ) const {
	return this->_prev;
}

void    EnemyShip::setPrev( EnemyShip* s ) {
	this->_prev = s;
}
