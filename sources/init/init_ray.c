//
//           :::      ::::::::
//         :+:      :+:    :+:     init_ray.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 15:57 by alegent
//

#include "wolf3d.h"

/*
** INITIALIZE RAYON WITH CAMERA VARIABLES
*/

void			init_ray(t_ray *ray, t_cam *cam, int x)
{
	ray->pos.x = cam->pos.x;
	ray->pos.y = cam->pos.y;
	ray->dir.x = cam->dir.x +
				 cam->plane.x * (2 * x / (double) WIN_SIZE_X - 1);
	ray->dir.y = cam->dir.y +
				 cam->plane.y * (2 * x / (double) WIN_SIZE_X - 1);
}
