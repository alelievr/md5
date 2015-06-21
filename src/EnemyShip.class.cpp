#include "EnemyShip.class.hpp"
#include "ft_retro.hpp"

EnemyShip::EnemyShip(void) : Ship("Enemy", 0, 0, 0, 0)
{

}

EnemyShip::EnemyShip(std::string name, int x, int y, int hp, int maxhp) : Ship(name, x, y, hp, maxhp)
{
	static std::string m[] = MASK_ENEMYSHIP;
	this->setNext(NULL);
	this->setPrev(NULL);
	this->setMask(m[rand() % 4]);
	this->direction = -1;
	this->setDam(100);
	this->fireTimer = INTER_FIRE_ENEMY;
	this->moveTimer = INTER_MOVE_ENEMY;
	std::cout << "Enemy ship created with " << this->getDam() << std::endl;
}

EnemyShip::~EnemyShip(void)
{
	std::cout << "Enemy ship destroyed" << std::endl;
	if (this->getPrev() != NULL)
		this->getPrev()->setNext(this->getNext());
	if (this->getNext() != NULL)
		this->getNext()->setPrev(this->getPrev());
}

void	EnemyShip::fire(void)
{
	playSound(SOUND_LASER);
	this->fireTimer = clock() + INTER_FIRE_ENEMY + (rand() % 10000);
}

void	EnemyShip::die(void)
{
	playSound(SOUND_EXPLOSION);
	delete this;
}

void	EnemyShip::move(void)
{
	this->nextPosition();
	this->moveTimer = clock() + INTER_MOVE_ENEMY + (rand() % 10000);
//	std::cout << "EnemyShip moves at " << x << "/" << y << std::endl;
}
void EnemyShip::append( EnemyShip* newEnemyShip ) {
	if (this->getNext() == NULL) {
		this->setNext(newEnemyShip);
		this->getNext()->setPrev(this);
//		std::cout << "Appened to list" << std::endl;
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

void	EnemyShip::nextPosition(void)
{
	if (rand() % 3)
		this->setY(this->getY() + this->direction);
	else
	{
		if (rand() % 2)
			this->setX(this->getX() + 1);
		else
			this->setX(this->getX() - 1);
	}
}
