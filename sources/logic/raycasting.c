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
	double 		pwd;

	x = -1;
	while (++x < WIN_SIZE_X)
	{
		init_ray(&ray, cam, x);
		init_dda(&dda_n, &ray);
		pwd = (!dda(&dda_n))
			  ? (dda_n.map.x - ray.pos.x + (1 - dda_n.step.x) / 2) / ray.dir.x
			  : (dda_n.map.y - ray.pos.y + (1 - dda_n.step.y) / 2) / ray.dir.y;
		draw_wall(sdl, x, pwd);
	}
}