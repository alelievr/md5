#ifndef GAMESTATUS_HPP
# define GAMESTATUS_HPP
# include <iostream>
# include <string>
# include "ft_retro.h"

class		GameStatus
{
	private:
		PlayerShip	_ship;
		int	_difficulty;
		int	_speed;
		bool	_pause;


	public:
		GameStatus(PlayerShip a0, int a1, int a2);
		GameStatus(const GameStatus&);
		~GameStatus(void);

		GameStatus &	operator=(GameStatus const & src);
		EnemyShip	enemyList;
		Obstacle	obstacleList;
		Projectile	ProjList;

		void	PauseGame(void);

		void	EndGame(void);

		int	AddObstacle(int x, int y);

		void	DeleteObstacle(int index);

		int	AddEnemyShip(int x, int y);

		void	DeleteEnemyShip(int index);

		int	AddProjectile(int x, int y, int dir);

		void	DeleteProjectile(int index);

		PlayerShip	getShip(void) const;
		void	setShip(PlayerShip tmp);
		
		int	getDifficulty(void) const;
		void	setDifficulty(int tmp);
		
		int	getSpeed(void) const;
		void	setSpeed(int tmp);
		
		bool	getPause(void) const;
		void	setPause(bool tmp);
};

std::ostream &	operator<<(std::ostream & o, GameStatus const & r);

#endif
