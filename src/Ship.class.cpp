#include "Ship.class.hpp"


Ship::Ship(std::string a0, int a1, int a2, int a3, int a4) : _name(a0), _x(a1), _y(a2), _HP(a3), _MHP(a4)
{
	std::cout << "Default constructor called" << std::endl;
}

Ship::Ship(Ship const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Ship::~Ship(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Ship::fire(void)
{
	
}

void	Ship::die(void)
{
	
}

void	Ship::move(int x, int y)
{
	std::cout << "Ship move at " << x << "/" << y << std::endl;
}


Ship &	Ship::operator=(Ship const & src)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->_name = src.getName();
		this->_x = src.getX();
		this->_y = src.getY();
		this->_HP = src.getHP();
		this->_MHP = src.getMHP();
	}
	return (*this);
}

std::string	Ship::getName(void) const
{
	return (this->_name);
}

void	Ship::setName(std::string tmp)
{
	this->_name = tmp;
}

int	Ship::getX(void) const
{
	return (this->_x);
}

void	Ship::setX(int tmp)
{
	this->_x = tmp;
}

int	Ship::getY(void) const
{
	return (this->_y);
}

void	Ship::setY(int tmp)
{
	this->_y = tmp;
}

int	Ship::getHP(void) const
{
	return (this->_HP);
}

void	Ship::setHP(int tmp)
{
	this->_HP = tmp;
}

int	Ship::getMHP(void) const
{
	return (this->_MHP);
}

void	Ship::setMHP(int tmp)
{
	this->_MHP = tmp;
}

std::ostream &	operator<<(std::ostream & o, Ship const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}
