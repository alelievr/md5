#ifndef GAMESTATUS_HPP
# define GAMESTATUS_HPP
# include "ft_retro.h"

class		GameStatus
{
	private:
		PlayerShip	_ship;
		int	_difficulty;
		int	_speed;
		bool	_pause;
		EnemyShip *	_enemyList;
		Obstacle *	_obstacleList;


	public:
		GameStatus(PlayerShip a0, int a1, int a2);
		~GameStatus(void);

		void	PauseGame(void);

		void	EndGame(void);

		PlayerShip	getShip(void) const;
		void	setShip(PlayerShip tmp);
		
		int	getDifficulty(void) const;
		void	setDifficulty(int tmp);
		
		int	getSpeed(void) const;
		void	setSpeed(int tmp);
		
		bool	getPause(void) const;
		void	setPause(bool tmp);
		
		EnemyShip *	getEnemyList(void) const;
		void	setEnemyList(EnemyShip * tmp);
		
		Obstacle *	getObstacleList(void) const;
		void	setObstacleList(Obstacle * tmp);
};

//std::ostream &	operator<<(std::ostream & o, GameStatus const & r);

#endif
