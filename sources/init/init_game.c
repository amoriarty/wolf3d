/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:18:28 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:44:51 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool				init_game(t_game *game)
{
	int				i;

	game->loop = TRUE;
	if (!init_cam(&(game->cam)))
		return (FAILURE);
	i = -1;
	while (++i < 4)
		game->arrow[i] = 0;
	return (SUCCESS);
}
