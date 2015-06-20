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

int	GameStatus::AddObstacle(int x, int y) 
{
	Obstacle *	tmp;
	Obstacle *	tmp2;

	tmp = this->obstacleList.next;
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = new Obstacle(x, y);
		tmp->next = tmp2;
		tmp2->prev = tmp;
		return (tmp2->getIndex());
	} else {
		tmp = new Obstacle(x, y);
		tmp->next = NULL;
		tmp->prev = NULL;
		this->obstacleList.next = tmp;
		return (tmp->getIndex());
	}
}

void	GameStatus::DeleteObstacle(int index) 
{
	(void)index;
}

int	GameStatus::AddEnemyShip(int x, int y) 
{
	(void)x;
	(void)y;
	return (0);
}

void	GameStatus::DeleteEnemyShip(int index) 
{
	(void)index;
}

int	GameStatus::AddProjectile(int x, int y, int dir) 
{
	(void)x;
	(void)y;
	(void)dir;
	return (0);
}

void	GameStatus::DeleteProjectile(int index) 
{
	(void)index;
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
