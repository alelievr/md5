#include "Projectile.class.hpp"
#include "Ship.class.hpp"
#include "ft_retro.hpp"

Projectile::Projectile(void) : Ship("Projectile", 0, 0, 50000, 50000)
{
	this->direction = 1;
}

Projectile::Projectile(int a0, int a1, int a2, int d, char a3) : Ship("Projectile", a0, a1, 500000, 500000)
{
	this->setNext(NULL);
	this->setPrev(NULL);
	this->direction = a2;
	this->c = a3;
	this->setDam(d);
	this->moveTimer = INTER_MOVE_PROJECTILE;
	this->speed = 0;
}

Projectile::Projectile(Projectile const & src)
{
	*this = src;
}

Projectile::~Projectile(void)
{
	if (this->getPrev() != NULL)
		this->getPrev()->setNext(this->getNext());
	if (this->getNext() != NULL)
		this->getNext()->setPrev(this->getPrev());
}

Projectile &	Projectile::operator=(Projectile const & src)
{
	if (this != &src) {
		this->setX(src.getX());
		this->setY(src.getY());
		this->speed = src.speed;
		this->direction = src.direction;
		this->c = src.c;
	}
	return (*this);
}

void		Projectile::move(void)
{
	this->nextPosition();
	this->moveTimer = clock() + INTER_MOVE_PROJECTILE + (rand() % 10000);
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
