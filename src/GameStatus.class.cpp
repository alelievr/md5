#include "GameStatus.class.hpp"


GameStatus::GameStatus(PlayerShip a0, int a1, int a2) : _ship(a0), _difficulty(a1), _speed(a2)
{
	std::cout << "Default constructor called" << std::endl;
	this->_pause = false;
	this->_enemyList = NULL;
	this->_obstacleList = NULL;
}

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


/*GameStatus &	GameStatus::operator=(GameStatus const & src)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &src) {
		this->_ship = src.getShip();
		this->_difficulty = src.getDifficulty();
		this->_speed = src.getSpeed();
		this->_pause = src.getPause();
		this->_enemyList = src.getEnemyList();
		this->_obstacleList = src.getObstacleList();
	}
	return (*this);
}*/

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

EnemyShip *	GameStatus::getEnemyList(void) const
{
	return (this->_enemyList);
}

void	GameStatus::setEnemyList(EnemyShip * tmp)
{
	this->_enemyList = tmp;
}

Obstacle *	GameStatus::getObstacleList(void) const
{
	return (this->_obstacleList);
}

void	GameStatus::setObstacleList(Obstacle * tmp)
{
	this->_obstacleList = tmp;
}

std::ostream &	operator<<(std::ostream & o, GameStatus const & r)
{
	o << "tostring of the class" << std::endl;
	(void)r;
	return (o);
}
