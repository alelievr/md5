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
}

Obstacle &	Obstacle::operator=(Obstacle const & src)
{
	if (this != &src)
	{
		this->setName(src.getName());
		this->setX(src.getX());
		this->setY(src.getY());
		this->setHP(src.getHP());
		this->setMHP(src.getMHP());
		this->setMask(src.getMask());
		this->setDam(src.getDam());
		this->setMask(src.getMask());
		this->setDisplay(true);
		this->setHeight(src.getHeight());
		this->setWidth(src.getWidth());
	}
	return (*this);
}

Obstacle::~Obstacle(void)
{
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
