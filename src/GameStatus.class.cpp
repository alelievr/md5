#include "GameStatus.class.hpp"


GameStatus::GameStatus(PlayerShip a0, int a1, int a2) : _ship(a0), _difficulty(a1), _speed(a2)
{
	std::cout << "Default constructor called" << std::endl;
	this->_pause = true;
	this->enemyList.setDisplay(false);
	this->obstacleList.setDisplay(false);
	this->ProjList.setDisplay(false);
}

/*GameStatus::GameStatus(GameStatus const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}*/

GameStatus::~GameStatus(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	GameStatus::PauseGame(void) 
{
	
}

void	GameStatus::EndGame(void) 
{
	
}

void	GameStatus::Colision(void)
{
	Projectile *	tmpP;
	EnemyShip *		tmpE;

	tmpP = this->enemyList.next;
	while (tmpP)
	{
		tmpE = this->projList.next;
		// EnemyShip colision:
		while (tmpE)
		{
			if (tmpP.getX() >= tmpE.getX()
					&& tmpP.getX <= tmpE.getX() + tmpE.getWidth())
				if (tmpP.getY() >= tmpE.getY()
						&& tmpP.getY <= tmpE.getY() + tmpE.getHeight())
					tmpE.takeDam(tmpP.getDam());
			tmpE = tmpE->next;
		}

		//PlayerShip colision:
		if (tmpP.getX() >= this->_ship.getX()
				&& tmpP.getX() <= this->_ship.getX() + this->_ship.getWidth())
			if (tmpP.getY() >= this->_ship.getY()
					&& tmpP.getY() <= this->_ship.getY() + this->_ship.getHeight())
				this->_ship.takeDam(tmpP.getDam());
		tmpP = tmpP->next;
	}
}

GameStatus &	GameStatus::operator=(GameStatus const & src)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->_ship = src.getShip();
		this->_difficulty = src.getDifficulty();
		this->_speed = src.getSpeed();
		this->_pause = src.getPause();
		this->enemyList = src.enemyList;
		this->obstacleList = src.obstacleList;
		this->ProjList = src.ProjList;
	}
	return (*this);
}

PlayerShip	GameStatus::getShip(void) const
{
	return (this->_ship);
}

void	GameStatus::setShip(PlayerShip tmp)
{
	this->_ship = tmp;
}

int	GameStatus::getDifficulty(void) const
{
	return (this->_difficulty);
}

void	GameStatus::setDifficulty(int tmp)
{
	this->_difficulty = tmp;
}

int	GameStatus::getSpeed(void) const
{
	return (this->_speed);
}

void	GameStatus::setSpeed(int tmp)
{
	this->_speed = tmp;
}

bool	GameStatus::getPause(void) const
{
	return (this->_pause);
}

void	GameStatus::setPause(bool tmp)
{
	this->_pause = tmp;
}

std::ostream &	operator<<(std::ostream & o, GameStatus const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}
