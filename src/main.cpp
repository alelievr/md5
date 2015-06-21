#include "ft_retro.hpp"
#include <chrono>
#include <unistd.h>
#include <ctime>

std::string		sgetl( std::string s ) {
	if (getline(std::cin, s) == 0) {
//		std::cout << "exit" << std::endl;
		exit(0);
	}
	return (s);
}

void	loop( GameStatus & gs ) {
	sleep(1);
	get_key();
	/*if (datas->key == KEY_RESIZE)
	{
		resize_2048(datas);
		display_2048(datas);
		display_2048(datas);
	}*/
	display(gs);
	gs.Colision();
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
	   scrollok(stdscr, TRUE);

//	gs.EndGame();
//	gs.PauseGame();
	gs.obstacleList.append(new Obstacle(1, 2));
	gs.obstacleList.append(new Obstacle(2, 2));
	gs.projList.append(new Projectile(10, 8, 1, '|'));
	gs.enemyList.append(new EnemyShip("Nyan", 10, 15, 42, 42));

	while (42)
		loop(gs);
}
