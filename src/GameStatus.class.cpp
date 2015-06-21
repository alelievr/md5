#include "GameStatus.class.hpp"

GameStatus::GameStatus(PlayerShip a0, int a1, int a2) : _difficulty(a1), _speed(a2), player(a0)
{
	srand(time(NULL));
//	std::cout << "Default constructor called" << std::endl;
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
//	std::cout << "Destructor called" << std::endl;
}

void	GameStatus::PauseGame(void) 
{
	std::string pausegame = ""
		" ________  ________  ___  ___  ________  _______      \n"
"|\\   __  \\|\\   __  \\|\\  \\|\\  \\|\\   ____\\|\\  ___ \\     \n"
"\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\___|\\ \\   __/|    \n"
" \\ \\   ____\\ \\   __  \\ \\  \\\\\\  \\ \\_____  \\ \\  \\_|/__  \n"
"  \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\\\\\  \\|____|\\  \\ \\  \\_|\\ \\ \n"
"   \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\____\\_\\  \\ \\_______\\\n"
"    \\|__|     \\|__|\\|__|\\|_______|\\_________\\|_______|\n"
"                                 \\|_________|";
	
	std::cout << pausegame << std::endl;
}

void	GameStatus::EndGame(void) 
{
	std::string endgame = " ________  ________  _____ ______   _______           ________  ___      ___ _______   ________     \n\
|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\    \n\
\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\   \n\
 \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\  \n\
  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\| \n\
   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\ \n\
    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|__|/       \\|_______|\\|__|\\|__|";
	std::cout << endgame << std::endl;
}

void	GameStatus::Colision(void)
{
	Projectile *	tmpP;
	EnemyShip *		tmpE;
	Obstacle *		tmpO;

	tmpP = this->projList.getNext();
	while (tmpP)
	{
		// Obstacle collisions:
		tmpO = this->obstacleList.getNext();
		while (tmpO)
		{
			if (tmpP->getX() >= tmpO->getX() &&
					tmpP->getX() <= tmpO->getX() + tmpO->getWidth())
				if (tmpP->getY() >= tmpO->getY() &&
						tmpP->getY() <= tmpO->getY() + tmpO->getHeight())
				{
					tmpO->takeDam(tmpP->getDam());
					std::cout << "obstacle colision !" << std::endl;
				}
			tmpO = tmpO->getNext();
		}

		tmpE = this->enemyList.getNext();
		// EnemyShip colision:
		while (tmpE)
		{
			if (tmpP->getX() >= tmpE->getX()
					&& tmpP->getX() <= tmpE->getX() + tmpE->getWidth())
				if (tmpP->getY() >= tmpE->getY()
						&& tmpP->getY() <= tmpE->getY() + tmpE->getHeight())
				{
					tmpE->takeDam(tmpP->getDam());
					std::cout << "enemy colision !" << std::endl;
				}
			tmpE = tmpE->next;
		}

		//PlayerShip colision:
		if (tmpP->getX() >= this->player.getX()
				&& tmpP->getX() <= this->player.getX() + this->player.getWidth())
			if (tmpP->getY() >= this->player.getY()
					&& tmpP->getY() <= this->player.getY() + this->player.getHeight())
			{
				this->player.takeDam(tmpP->getDam());
				std::cout << "playerShip colision !" << std::endl;
			}
		tmpP = tmpP->getNext();
	}

	// Obstacle collisions with playerShip:
	tmpO = this->obstacleList.getNext();
	while (tmpO)
	{
		if (this->player.getX() >= tmpO->getX() &&
				this->player.getX() <= tmpO->getX() + tmpO->getWidth())
			if (this->player.getY() >= tmpO->getY() &&
					this->player.getY() <= tmpO->getY() + tmpO->getHeight())
			{
				this->player.takeDam(tmpO->getDam());
				tmpO->takeDam(this->player.getDam());
				std::cout << "obstacle colision with you !" << std::endl;
			}
		tmpO = tmpO->getNext();
	}

	tmpE = this->enemyList.getNext();
	// EnemyShip colision with you:
	while (tmpE)
	{
		if (this->player.getX() >= tmpE->getX()
				&& this->player.getX() <= tmpE->getX() + tmpE->getWidth())
			if (this->player.getY() >= tmpE->getY()
					&& this->player.getY() <= tmpE->getY() + tmpE->getHeight())
			{
				tmpE->takeDam(this->player.getDam());
				this->player.takeDam(tmpE->getDam());
				std::cout << "enemy colision with you!" << std::endl;
			}
		tmpE = tmpE->next;
	}
}

GameStatus &	GameStatus::operator=(GameStatus const & src)
{
//	std::cout << "Assignment operator called" << std::endl;

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
