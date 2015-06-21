/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:54:20 by alelievr          #+#    #+#             */
/*   Updated: 2015/06/21 05:45:42 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include <chrono>
#include <unistd.h>
#include <ctime>
#include <fstream>

std::string		sgetl( std::string s ) {
	if (getline(std::cin, s) == 0) {
//		std::cout << "exit" << std::endl;
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

void	loop( GameStatus & gs ) {
	gs.Update();
	get_key();
	/*if (datas->key == KEY_RESIZE)
	{
		resize_2048(datas);
		display_2048(datas);
		display_2048(datas);
	}*/
	gs.Colision();
	display(gs);
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
