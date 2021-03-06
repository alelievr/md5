#include "Ship.class.hpp"

Ship::Ship(void)
{
	Ship("", 0, 0, 0, 0);
	this->setDisplay(false);
}

Ship::Ship(std::string a0, int a1, int a2, int a3, int a4) : _name(a0), _x(a1), _y(a2), _HP(a3), _MHP(a4)
{
	//this->setNext(NULL);
	//this->setPrev(NULL);
	this->direction = 0;
	this->_damage = 0;
	this->_index = genIndex();
	this->setDisplay(true);
}

Ship::Ship(Ship const & src)
{
	*this = src;
	this->_index = genIndex();
}

Ship::~Ship(void)
{
}

int		Ship::getDam( void  ) const {
	return this->_damage;
}

void		Ship::setDam( int d ) {
	this->_damage = d;
}

void	Ship::takeDam( int d ) {
	this->_HP -= d;
	if (this->_HP < 0)
		this->die();
}

void	Ship::fire(void)
{
	
}

void	Ship::die(void)
{
	
}

void	Ship::move(void)
{

}

void		Ship::nextPosition(void)
{
	this->_y += this->direction;
}

Ship &	Ship::operator=(Ship const & src)
{
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

int	Ship::getIndex(void) const
{
	return (this->_index);
}

void	Ship::setIndex(int tmp)
{
	this->_index = tmp;
}

int	Ship::getHeight(void) const
{
	return (this->_height);
}

void	Ship::setHeight(int tmp)
{
	this->_height = tmp;
}

int	Ship::getWidth(void) const
{
	return (this->_width);
}

void	Ship::setWidth(int tmp)
{
	this->_width = tmp;
}

void	Ship::setDisplay(bool sta)
{
	this->_display = sta;
}

std::ostream &	operator<<(std::ostream & o, Ship const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}

int		Ship::genIndex(void)
{
	static int	i = -1;

	return (++i);
}

void	Ship::setMask(std::string m)
{
	int		w = 0, h = 0;

	for (int i = 0; m[i] && m[i] != '\n'; i++)
		w++;
	for (int i = 0; m[i]; i++)
		if (m[i] == '\n')
			h++;
	this->_width = w;
	this->_height = h;
	this->data = m;
}

std::string		Ship::getMask(void) const
{
	return (this->data);
}
