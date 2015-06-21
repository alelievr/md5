#include "ft_retro.hpp"
#include <chrono>
#include <unistd.h>
#include <ctime>
#include <fstream>

std::string		sgetl( std::string s ) {
	if (getline(std::cin, s) == 0) {
		std::cout << "exit" << std::endl;
		exit(0);
	}
	return (s);
}

void		genRandomTruc(GameStatus & gs)
{
	static unsigned long ObstacleTimer = 0;
	static unsigned long EnemyTimer = 0;

/*	if (clock() >= ObstacleTimer)
	{
		gs.obstacleList.append(new Obstacle(rand() % 80, 40 + rand() % 20));
		ObstacleTimer = clock() + INTER_OBSTACLE_APEAR;
	}*/
	if (clock() >= EnemyTimer)
	{
		gs.enemyList.append(new EnemyShip("Nyancat", rand() % 80, 40 + rand() % 15, 20 + rand() % 21, 45));
		EnemyTimer = clock() + INTER_ENEMY_APEAR;
	}
	(void)ObstacleTimer;
}

static int	loop( GameStatus & gs ) {
	genRandomTruc(gs);
	get_key(gs);
	if (gs.getKey() == KEY_RESIZE) {
		resize(gs);
/*		display(datas);
		display(datas);*/
	}
	if (gs.getKey() == 033 && getch() < 0) {
		return (-1);
	}

	if (clock() >= BOSS_TICK_APEAR)
	{
		//olol
	}
	gs.Update();
	gs.Colision();
	display(gs);
	return (0);
}

int		main(void)
{
	playBackground();
	loadSounds();
	PlayerShip	ps("player", 10, 10, 10, 10);
	GameStatus	gs(ps, 0, 1);
	initscr();
	raw();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	resize(gs);

	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);

//	gs.EndGame();
//	gs.PauseGame();
//	gs.obstacleList.append(new Obstacle(1, 2));
//	gs.obstacleList.append(new Obstacle(2, 2));
//	gs.projList.append(new Projectile(10, 8, 1, '|'));
	gs.enemyList.append(new EnemyShip("Nyan", 10, 20, 42, 42));

	while (!loop(gs));
	scrollok(stdscr, TRUE);
	curs_set(1);
	endwin();
}
