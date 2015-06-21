#include "Obstacle.class.hpp"
#include "Ship.class.hpp"
#include "ft_retro.hpp"

Obstacle::Obstacle(void)
{
	static	std::string m[] = MASK_OBSTACLE;

	this->setDisplay(false);
	this->setMask(m[rand() % 4]);
	this->direction = -1;
	this->moveTimer = INTER_MOVE_OBSTACLE;
	Obstacle(0, 0);
}

Obstacle::Obstacle(int x, int y) : Ship("Asteroid", x, y, 500000, 500000)
{
	this->setNext(NULL);
	this->setPrev(NULL);
//	std::cout << "new ostacle in " << x << "/" << y << std::endl;
}

Obstacle::~Obstacle(void)
{
//	std::cout << "Destructed Asteroid" << std::endl;
	if (this->getPrev() != NULL)
		this->getPrev()->setNext(this->getNext());
	if (this->getNext() != NULL)
		this->getNext()->setPrev(this->getPrev());
}

void		Obstacle::fire(void) { }

void		Obstacle::die(void) { }

void		Obstacle::move(void)
{
	this->nextPosition();
	this->moveTimer = clock() + INTER_MOVE_OBSTACLE + (rand() % 10000);
}

void Obstacle::append( Obstacle* newObstacle ) {
	if (this->getNext() == NULL) {
		this->setNext(newObstacle);
		this->getNext()->setPrev(this);
//		std::cout << "Appened to list" << std::endl;
	} else
		this->getNext()->append(newObstacle);
}

Obstacle*   Obstacle::getNext( void ) const {
    return this->_next;
}

void    Obstacle::setNext( Obstacle* s ) {
    this->_next = s;
}

Obstacle*   Obstacle::getPrev( void ) const {
    return this->_prev;
}

void    Obstacle::setPrev( Obstacle* s ) {
    this->_prev = s;
}
