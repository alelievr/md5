#include "Projectile.class.hpp"

Projectile::Projectile(void) : Ship("Projectile", 0, 0, 50000, 50000)
{
	this->direction = 1;
}

Projectile::Projectile(int a0, int a1, int a2, char a3) : Ship("Projectile", a0, a1, 500000, 500000)
{
	this->direction = a2;
	this->character = a3;
	this->speed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Projectile::Projectile(Projectile const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Projectile::~Projectile(void)
{
	std::cout << "Destructor called" << std::endl;
}

Projectile &	Projectile::operator=(Projectile const & src)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->x = src.x;
		this->y = src.y;
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
