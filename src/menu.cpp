#include "ft_retro.hpp"

/*static int				choice_size(t_2048 *datas)
{
	int					c;
	int					tmp;

	tmp = datas->tmp[3];
	datas->tmp[3] = 0;
	if ((c = get_choice(datas, 5, 4, "4", "5", "6", "7", "8", NULL)) < 0)
	{
		display_2048(datas);
		datas->tmp[3] = tmp;
		return (-1);
	}
	datas->grid_size = c + 4;
	resize_2048(datas);
	grid_init(datas);
	return (0);
}*/

int						menu(GameStatus& gs) {
	int choice;
	int loop;

	loop = 1;
	while (loop) {
		wrefresh(stdscr);
		choice = get_choice(gs, 2, 2, "Quit", NULL);
		if (choice == 0)
			return (-1);
	//	else if (choice == 1)
	//		loop = choice_size(datas);
		else
			break ;
	}
//	datas->tmp[3] = 0;
	timeout(0);
	return (0);
}
