#ifndef GAME_STATUS_CLASS_HPP
# define GAME_STATUS_CLASS_HPP
# include <iostream>
# include <string>
# include "PlayerShip.class.hpp"
# include "EnemyShip.class.hpp"
# include "Obstacle.class.hpp"
# include "Projectile.class.hpp"

class		GameStatus {
	private:
		int	_difficulty;
		int	_speed;
		bool	_pause;


	public:
		GameStatus(PlayerShip a0, int a1, int a2);
		GameStatus(const GameStatus&);
		~GameStatus(void);

		GameStatus &	operator=(GameStatus const &);
		EnemyShip	enemyList;
		Obstacle	obstacleList;
		Projectile	projList;
		PlayerShip	player;

		void	Colision(void);
		void	Update(void);
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
};

std::ostream &	operator<<(std::ostream & o, GameStatus const & r);
#endif
