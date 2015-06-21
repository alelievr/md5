#include "ft_retro.hpp"

void					resize(GameStatus& gs)
{
	struct winsize			ws;

	ioctl(0, TIOCGWINSZ, &ws);
	gs.setWidth(ws.ws_col);
	gs.setHeight(ws.ws_row);
}
