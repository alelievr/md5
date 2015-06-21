/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blemee <blemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:35:41 by blemee            #+#    #+#             */
/*   Updated: 2015/06/21 08:47:48 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

static void	display_mask(GameStatus& gs, int x, int y, std::string mask) {
	char buf[2] = {0};
	int xOffset = 0;
	int yOffset = 0;

	mvaddstr(0, 0, std::to_string(gs.getWidth()).c_str());
	mvaddstr(0, 5, std::to_string(gs.getHeight()).c_str());
	for (int i = 0; mask[i]; i++) {
		if (mask[i] == '\n') {
			yOffset++;
			xOffset = 0;
		}
		else if (mask[i] != ' ') {
			buf[0] = mask[i];
			mvaddstr(gs.getHeight() - y + yOffset, x + xOffset++, buf);
		}
		else
			xOffset++;
	}
}

int		display(GameStatus& gs ) {
	Obstacle* tmpO;
	EnemyShip* tmpE;
	Projectile* tmpP;

	erase();

	tmpO = &gs.obstacleList;
	while ((tmpO = tmpO->getNext())) {
		display_mask(gs, tmpO->getX(), tmpO->getY(), tmpO->getMask());
	}

	tmpE = &gs.enemyList;
	while ((tmpE = tmpE->getNext())) {
		display_mask(gs, tmpE->getX(), tmpE->getY(), tmpE->getMask());
	}

	tmpP = &gs.projList;
	while ((tmpP = tmpP->getNext())) {
		display_mask(gs, tmpP->getX(), tmpP->getY(), tmpP->getMask());
	}

	display_mask(gs, gs.player.getX(), gs.player.getY(), gs.player.getMask());

	refresh();
	return (0);
}
