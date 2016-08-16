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

void 			raycasting(t_sdl *sdl, t_cam *cam)
{
	int 		x;
	t_ray		ray;
	t_dda		dda_n;

	x = -1;
	draw_background(sdl);
	while (++x < WIN_SIZE_X)
	{
		init_ray(&ray, cam, x);
		init_dda(&dda_n, &ray);
		dda_n.s = dda(&dda_n);
		draw_wall(sdl, x, &dda_n, &ray);
	}
	SDL_RenderPresent(sdl->win.renderer);
}