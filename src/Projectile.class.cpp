#include "Projectile.class.hpp"
#include "Ship.class.hpp"

Projectile::Projectile(void) : Ship("Projectile", 0, 0, 50000, 50000)
{
	this->direction = 1;
}

Projectile::Projectile(int a0, int a1, int a2, char a3) : Ship("Projectile", a0, a1, 500000, 500000)
{
	this->setNext(NULL);
	this->setPrev(NULL);
	this->direction = a2;
	this->c = a3;
	this->speed = 0;
//	std::cout << "Default constructor called" << std::endl;
}

Projectile::Projectile(Projectile const & src)
{
	*this = src;
//	std::cout << "Copy constructor called" << std::endl;
}

Projectile::~Projectile(void)
{
//	std::cout << "Destructor called" << std::endl;
	if (this->getPrev() != NULL)
		this->setPrev(this->getNext());
	if (this->getNext() != NULL)
		this->setNext(this->getNext());
}

Projectile &	Projectile::operator=(Projectile const & src)
{
//	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->setX(src.getX());
		this->setY(src.getY());
		this->speed = src.speed;
		this->direction = src.direction;
		this->c = src.c;
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Projectile const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}
void Projectile::append( Projectile* newProjectile ) {
	if (this->getNext() == NULL) {
		this->setNext(newProjectile);
		this->getNext()->setPrev(this);
//		std::cout << "Appened to list" << std::endl;
	} else
		this->getNext()->append(newProjectile);
}

Projectile*   Projectile::getNext( void ) const {
	return this->_next;
}

void    Projectile::setNext( Projectile* s ) {
	this->_next = s;
}

Projectile*   Projectile::getPrev( void ) const {
	return this->_prev;
}

void    Projectile::setPrev( Projectile* s ) {
	this->_prev = s;
}
