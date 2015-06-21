/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blemee <blemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:35:41 by blemee            #+#    #+#             */
/*   Updated: 2015/06/21 04:04:43 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

static void	display_mask(int x, int y, std::string mask) {
	mvaddstr(y, x, mask.c_str());
}

int		display(GameStatus& gs ) {
	Obstacle* tmpO;

	gs.obstacleList.append(new Obstacle(1, 2));
	gs.obstacleList.append(new Obstacle(2, 2));

	erase();

	tmpO = &gs.obstacleList;
	while ((tmpO = tmpO->getNext())) {
		display_mask(tmpO->getX(), tmpO->getY(), "O");//tmp0->getMask());
	}
	refresh();
	return (0);
}
