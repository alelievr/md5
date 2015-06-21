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
	get_key();
	/*if (datas->key == KEY_RESIZE)
	{
		resize_2048(datas);
		display_2048(datas);
		display_2048(datas);
	}*/
	display(gs);
/*
	Obstacle *	tmp;
	Obstacle *	tmp2;
	gm.obstacleList.append(new Obstacle(1, 2));
	gm.obstacleList.append(new Obstacle(2, 2));
	gm.obstacleList.append(new Obstacle(3, 2));
	gm.Colision();
	tmp = gm.obstacleList.getNext();
	while (tmp)
	{
		std::cout << "o in " << tmp->getX() << "/" << tmp->getY() << std::endl;
		tmp2 = tmp;
		tmp = tmp->getNext();
	}
	tmp = tmp2;
	while (tmp)
	{
		std::cout << "o in " << tmp->getX() << "/" << tmp->getY() << std::endl;
		tmp = tmp->getPrev();
	}*/
}

int		main(void)
{
	playBackground();
	loadSounds();
	PlayerShip	ps("player", 2, 2, 10, 10);
	GameStatus	gs(ps, 0, 1);
	initscr();
	raw();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	   scrollok(stdscr, TRUE);
//	gs.EndGame();
//	gs.PauseGame();
	while (42)
		loop(gs);
}
