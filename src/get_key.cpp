/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blemee <blemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 23:50:09 by blemee            #+#    #+#             */
/*   Updated: 2015/06/21 09:35:47 by blemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

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

int		get_key( GameStatus& gs )
{
	if (kbhit()) {
		gs.setKey(getch());
	}
	return (0);
}
