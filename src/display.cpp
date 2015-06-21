#include "ft_retro.hpp"

static void	display_mask(GameStatus& gs, int x, int y, int maskHeight, std::string mask) {
	char buf[2] = {0};
	int xOffset = 0;
	int yOffset = -maskHeight;
	(void)maskHeight;

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

void	draw_debug( GameStatus& gs ) {
	mvaddstr(0, 110, "KeyCode:");
	mvaddstr(0, 120, std::to_string(gs.getKey()).c_str());
	mvaddstr(0, 89, "Win.Width:");
	mvaddstr(0, 100, std::to_string(gs.getWidth()).c_str());
	mvaddstr(1, 88, "Win.Height:");
	mvaddstr(1, 100, std::to_string(gs.getHeight()).c_str());
}

void	draw_info( GameStatus& gs ) {
	mvaddstr(0, 10, "Health:");
	mvaddstr(0, 18, std::to_string(gs.player.getHP()).c_str());
	mvaddstr(1, 20, "/");
	mvaddstr(1, 22, std::to_string(gs.player.getMHP()).c_str());
	mvaddstr(0, 30, "Lives:");
	mvaddstr(1, 40, std::to_string(gs.player.getLife()).c_str());
	/*score
*/
}

void	draw_border( GameStatus& gs ) {
	static int move = 0;
	int x;
	int y;
	int xMax = gs.getWidth();
	int yMax = gs.getHeight();

	/* top border */
	y = 2;
	for(x = 0; x < xMax; x++) {
		mvaddstr(y, x, "_");
	}

	/* left border */
	x = 0;
	for(y = 3 + move; y < yMax; y += 2)
		mvaddstr(y, x, "|");
	for(y = 3 + !move; y < yMax; y += 2)
		mvaddstr(y, x, "]");
	
	/* right border */
	x = xMax - 1;
	for(y = 3 + move; y < yMax; y += 2)
		mvaddstr(y, x, "|");
	for(y = 3 + !move; y < yMax; y += 2)
		mvaddstr(y, x, "[");

	draw_info(gs);
	draw_debug(gs);

	move = !move;
}

int		display( GameStatus& gs ) {
	Obstacle* tmpO;
	EnemyShip* tmpE;
	Projectile* tmpP;

	erase();

	draw_border(gs);

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
		display_mask(gs, tmpP->getX(), tmpP->getY(), tmpP->getHeight(), tmpP->getMask());
	}

	display_mask(gs, gs.player.getX(), gs.player.getY(), gs.player.getHeight(), gs.player.getMask());

	refresh();
	return (0);
}
