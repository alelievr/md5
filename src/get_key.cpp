/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blemee <blemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 23:50:09 by blemee            #+#    #+#             */
/*   Updated: 2015/06/21 03:05:03 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.h"

int		kbhit( void )
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
	} else {
		return 0;
	}
}

int		get_key( void )
{
	if (kbhit()) {
	//	printw("Key pressed! It was: %d\n", getch());
	//	refresh();
	} else {
	//	printw("No key pressed yet...\n");
	//	refresh();
	}
	return (0);
}
