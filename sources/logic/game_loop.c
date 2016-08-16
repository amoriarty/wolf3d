//
//           :::      ::::::::
//         :+:      :+:    :+:     game_loop.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 17:17 by alegent
//

#include "wolf3d.h"

/*
** GAME LOOP
*/

int 			game_loop(t_all *all)
{
	init_cam(&(all->game.cam));
	//TODO PRELOAD TEXTURES
	all->sdl.wall = IMG_Load(GREYSTONE_TEXTURE);
	while (all->game.loop)
	{
		raycasting(all);
		wait_event(all);
	}
	return (FAILURE);
}