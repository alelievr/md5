#include "Obstacle.class.hpp"
#include "Ship.class.hpp"
#include "ft_retro.hpp"

Obstacle::Obstacle(void)
{
	static	std::string m[] = MASK_OBSTACLE;

	this->setDisplay(false);
	this->setMask(m[rand() % 4]);
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
		this->setPrev(this->getNext());
	if (this->getNext() != NULL)
		this->setNext(this->getNext());
}

void		Obstacle::fire(void) { }

void		Obstacle::die(void) { }

void		Obstacle::move(int x, int y) { (void)x; (void)y; }

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
