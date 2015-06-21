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

void	debug(std::string t)
{
	std::ofstream file;

	file.open("debug.txt", std::ios::app | std::ios::out | std::ios::in);
	file << t;
	file.close();
}

<<<<<<< HEAD
static int	loop( GameStatus & gs ) {
	get_key(gs);
	if (gs.getKey() == KEY_RESIZE) {
		resize(gs);
/*		display(datas);
		display(datas);*/
	}
	if (gs.getKey() == 033 && getch() < 0) {
		return (-1);
	}

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

//	gs.EndGame();
//	gs.PauseGame();
	gs.obstacleList.append(new Obstacle(1, 2));
	gs.obstacleList.append(new Obstacle(2, 2));
	gs.projList.append(new Projectile(10, 8, 1, '|'));
	gs.enemyList.append(new EnemyShip("Nyan", 10, 15, 42, 42));

	while (!loop(gs));
	scrollok(stdscr, TRUE);
	curs_set(1);
	endwin();
}
