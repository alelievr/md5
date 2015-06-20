/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 00:54:20 by alelievr          #+#    #+#             */
/*   Updated: 2015/06/20 02:54:50 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.h"

std::string		sgetl(std::string s)
{
	if (getline(std::cin, s) == 0)
	{
		std::cout << "exit" << std::endl;
		exit(0);
	}
	return (s);
}

void	loop(void)
{
	exit(0);
}

int		main(void)
{
	PlayerShip	ps("player", 1, 1, 10, 10);
	GameStatus	gs(ps, 0, 1);
	while (42)
		loop();
}
