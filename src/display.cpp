#include "ft_retro.hpp"

static void	display_mask(GameStatus& gs, int x, int y, int maskHeight, std::string mask) {
	char buf[2] = {0};
	int xOffset = 0;
	int yOffset = -maskHeight;
	(void)maskHeight;

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
		display_mask(gs, tmpO->getX(), tmpO->getY(), tmpO->getHeight(), tmpO->getMask());
	}

	tmpE = &gs.enemyList;
	while ((tmpE = tmpE->getNext())) {
		display_mask(gs, tmpE->getX(), tmpE->getY(), tmpE->getHeight(), tmpE->getMask());
	}

	tmpP = &gs.projList;
	while ((tmpP = tmpP->getNext())) {
		display_mask(gs, tmpP->getX(), tmpP->getY(), tmpP->getHeight(), "|");
	}

	display_mask(gs, gs.player.getX(), gs.player.getY(), gs.player.getHeight(), gs.player.getMask());

	mvaddstr(0, 15, std::to_string(gs.getKey()).c_str());

	refresh();
	return (0);
}
