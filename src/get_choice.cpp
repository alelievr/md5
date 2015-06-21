#include "ft_retro.hpp"

static void				choice_aff(GameStatus& gs, int max, char *entries[32])
{
	int					i;

/*	if (datas->tmp[4]) {
		//resize(gs);
		display(gs);
	}*/
	i = -1;
	while (entries[++i] != NULL)
	{
		if (i == datas->tmp[3])
			wattron(datas->subw, A_REVERSE);
		mvwprintw(datas->subw, i + 1, 1, "%C%-*s ",
				(i == datas->tmp[3] ? '>' : ' '), max, entries[i]);
		if (i == datas->tmp[3])
			wattroff(datas->subw, A_REVERSE);
	}
	wattron(datas->subw, COLOR_PAIR(33));
	wborder(datas->subw, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(datas->subw, COLOR_PAIR(33));
	refresh();
	wrefresh(datas->subw);
	datas->tmp[4] = 0;
}

static int				get_choice_ftn(GameStatus& gs, int n, int max, char *entries[32]) {
	int					key;

	while (42)
	{
		if (key == KEY_RESIZE)
			datas->tmp[4] = 1;
		if (datas->rows < datas->tmp[6] + 1)
			return (-1);
		choice_aff(datas, max, entries);
		if ((key = getch()) == 033)
		{
			timeout(0);
			if (getch() < 0)
				return (-1);
			timeout(-1);
			if ((key = getch()) == 'A')
				--(datas->tmp[3]);
			else if (key == 'B')
				++(datas->tmp[3]);
			if ((datas->tmp[3] < 0) || (datas->tmp[3] > n - 1))
				datas->tmp[3] = (datas->tmp[3] < 0 ? n - 1 : 0);
		}
		else if (key == 10)
			return (datas->tmp[3]);
	}
}

int						get_choice(GamesStatus& gs, int li, int co, ...)
{
	va_list				vl;
	char				*entries[32];
	int					i;
	int					max;
	int					tmp;

	datas->tmp[6] = li;
	timeout(-1);
	va_start(vl, co);
	max = 5;
	i = -1;
	while ((entries[++i] = va_arg(vl, char *)) != NULL)
		if ((tmp = (int)ft_strlen(entries[i])) > max)
			max = tmp;
	va_end(vl);
	datas->subw = newwin(i + 2, max + 4, li, co);
	tmp = get_choice_ftn(gs, i, max, entries);
	delwin(datas->subw);
	timeout(0);
	return (tmp);
}
