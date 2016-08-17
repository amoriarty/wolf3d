//
//           :::      ::::::::
//         :+:      :+:    :+:     init_game.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 14:03 by alegent
//

#include "wolf3d.h"

t_bool				init_game(t_game *game)
{
	int 			i;

	game->loop = TRUE;
	if (!init_cam(&(game->cam)))
		return (FAILURE);
	i = -1;
	while (++i < 4)
		game->arrow[i] = 0;
	return (SUCCESS);
}