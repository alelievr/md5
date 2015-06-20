/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:54:20 by alelievr          #+#    #+#             */
/*   Updated: 2015/06/20 21:14:14 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.h"
#include <chrono>
#include <unistd.h>
#include <ctime>

std::string		sgetl(std::string s)
{
	if (getline(std::cin, s) == 0)
	{
		std::cout << "exit" << std::endl;
		exit(0);
	}
	return (s);
}

void	loop(GameStatus & gm)
{
	Obstacle *	tmp;
	Obstacle *	tmp2;
	gm.obstacleList.append(new Obstacle(1, 2));
	gm.obstacleList.append(new Obstacle(2, 2));
	gm.obstacleList.append(new Obstacle(3, 2));
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
	}
	exit(0);
}

int		main(void)
{
	PlayerShip	ps("player", 1, 1, 10, 10);
	GameStatus	gs(ps, 0, 1);
	while (42)
		loop(gs);
}
