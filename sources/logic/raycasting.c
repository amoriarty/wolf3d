//
//           :::      ::::::::
//         :+:      :+:    :+:     raycasting.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 16:00 by alegent
//

#include "wolf3d.h"

/*
** MY RAYCASTING ALGORITHM, MINIMIZE TO FUNCTIONS CALLED
*/

void 			raycasting(t_all *all)
{
	all->game.iter.x = -1;
	//TODO NO MORE BACKGROUND TO DRAW
	draw_background(&(all->sdl));
	while (++(all->game.iter.x) < WIN_SIZE_X)
	{
		init_ray(&(all->game.ray), &(all->game.cam), all->game.iter.x);
		init_dda(&(all->game.dda), &(all->game.ray));
		all->game.dda.s = dda(&(all->game.dda));
		draw_wall(all);
	}
	SDL_RenderPresent(all->sdl.win.renderer);
}