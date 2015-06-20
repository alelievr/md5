#include "GameStatus.class.hpp"


GameStatus::GameStatus(PlayerShip a0, int a1, int a2) : _difficulty(a1), _speed(a2), player(a0)
{
	std::cout << "Default constructor called" << std::endl;
	this->_pause = true;
	this->enemyList.setDisplay(false);
	this->obstacleList.setDisplay(false);
	this->projList.setDisplay(false);
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

	tmpP = this->projList.getNext();
	while (tmpP)
	{
		tmpE = this->enemyList.getNext();
		// EnemyShip colision:
		while (tmpE)
		{
			if (tmpP->getX() >= tmpE->getX()
					&& tmpP->getX() <= tmpE->getX() + tmpE->getWidth())
				if (tmpP->getY() >= tmpE->getY()
						&& tmpP->getY() <= tmpE->getY() + tmpE->getHeight())
					tmpE->takeDam(tmpP->getDam());
			tmpE = tmpE->next;
		}

		//PlayerShip colision:
		if (tmpP->getX() >= this->player.getX()
				&& tmpP->getX() <= this->player.getX() + this->player.getWidth())
			if (tmpP->getY() >= this->player.getY()
					&& tmpP->getY() <= this->player.getY() + this->player.getHeight())
				this->player.takeDam(tmpP->getDam());
		tmpP = tmpP->getNext();
	}
}

GameStatus &	GameStatus::operator=(GameStatus const & src)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->player = src.getShip();
		this->_difficulty = src.getDifficulty();
		this->_speed = src.getSpeed();
		this->_pause = src.getPause();
		this->enemyList = src.enemyList;
		this->obstacleList = src.obstacleList;
		this->projList = src.projList;
	}
	return (*this);
}

PlayerShip	GameStatus::getShip(void) const
{
	return (this->player);
}

void	GameStatus::setShip(PlayerShip tmp)
{
	this->player = tmp;
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
