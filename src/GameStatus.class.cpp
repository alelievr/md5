#include "GameStatus.class.hpp"
#include "ft_retro.hpp"

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
	Projectile *	tmpD;
	bool			toDelete;

	tmpP = this->projList.getNext();
	while (tmpP)
	{
		toDelete = false;
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
					toDelete = true;
			//		debug("obstacle colision !\n");
				}
			tmpO = tmpO->getNext();
		}

		tmpE = this->enemyList.getNext();
		// EnemyShip colision:
		while (tmpE)
		{
			if (tmpP->getX() >= tmpE->getX() && !toDelete
					&& tmpP->getX() <= tmpE->getX() + tmpE->getWidth())
				if (tmpP->getY() >= tmpE->getY()
						&& tmpP->getY() <= tmpE->getY() + tmpE->getHeight())
				{
					tmpE->takeDam(tmpP->getDam());
					toDelete = true;
			//		debug("enemy colision !\n");
				}
			tmpE = tmpE->next;
		}

		//PlayerShip colision:
		if (tmpP->getX() >= this->player.getX() && !toDelete
				&& tmpP->getX() <= this->player.getX() + this->player.getWidth())
			if (tmpP->getY() >= this->player.getY()
					&& tmpP->getY() <= this->player.getY() + this->player.getHeight())
				{
					this->player.takeDam(tmpP->getDam());
					toDelete = true;
				//	debug("playerShip colision !\n");
				}
		tmpD = tmpP;
		tmpP = tmpP->getNext();
		if (toDelete)
			delete tmpD;
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
			//	debug("obstacle colision with you !\n");
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
			//	debug("enemy colision with you!\n");
			}
		tmpE = tmpE->next;
	}
}

void		GameStatus::Update(void)
{
	Projectile *	tmpP;
	EnemyShip *		tmpE;
	Obstacle *		tmpO;

	tmpP = &this->projList;
	while ((tmpP = tmpP->getNext()))
		if (clock() >= tmpP->moveTimer)
			tmpP->move();
	tmpE = &this->enemyList;
	while ((tmpE = tmpE->getNext()))
	{
		if (clock() >= tmpE->moveTimer)
			tmpE->move();
		if (clock() >= tmpE->fireTimer)
		{
			this->projList.append(new Projectile(tmpE->getX() + tmpE->getWidth() / 2, tmpE->getY() + tmpE->direction, tmpE->direction, tmpE->getDam(), '|'));
			tmpE->fire();
		}
	}
	tmpO = &this->obstacleList;
	while ((tmpO = tmpO->getNext()))
		if (clock() >= tmpO->moveTimer)
			tmpO->move();
	if (this->getKey())
	{
		this->player.move(this->getKey());
		if (this->getKey() == 32)
		{
			this->projList.append(new Projectile(this->player.getX(), this->player.getY() + this->getHeight() + 5, this->player.direction, this->player.getDam(), '|'));
		}
		this->setKey(0);
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

int	GameStatus::getKey(void) const
{
	return (this->_key);
}

void	GameStatus::setKey(int tmp)
{
	this->_key = tmp;
}

int	GameStatus::getWidth(void) const
{
	return (this->_width);
}

void	GameStatus::setWidth(int tmp)
{
	this->_width = tmp;
}

int	GameStatus::getHeight(void) const
{
	return (this->_height);
}

void	GameStatus::setHeight(int tmp)
{
	this->_height = tmp;
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
