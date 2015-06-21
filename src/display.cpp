/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blemee <blemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:35:41 by blemee            #+#    #+#             */
/*   Updated: 2015/06/21 04:34:12 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

static void	display_mask(int x, int y, std::string mask) {
	mvaddstr(y, x, mask.c_str());
}

int		display(GameStatus& gs ) {
	Obstacle* tmpO;
	EnemyShip* tmpE;
	Projectile* tmpP;

	erase();

	tmpO = &gs.obstacleList;
	while ((tmpO = tmpO->getNext())) {
		display_mask(tmpO->getX(), tmpO->getY(), "O");//tmp0->getMask());
	}

	tmpE = &gs.enemyList;
	while ((tmpE = tmpE->getNext())) {
		display_mask(tmpE->getX(), tmpE->getY(), "E");//tmp0->getMask());
	}

	tmpP = &gs.projList;
	while ((tmpP = tmpP->getNext())) {
		display_mask(tmpP->getX(), tmpP->getY(), "|");//tmp0->getMask());
	}

	display_mask(gs.player.getX(), gs.player.getY(), "P");//tmp0->getMask());

	refresh();
	return (0);
}
