//
//           :::      ::::::::
//         :+:      :+:    :+:     init_dda.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 15:58 by alegent
//

#include "wolf3d.h"

/*
** INIT DDA NEEDED VARIABLE WITH THE RAYON VARIABLES
*/

void 			init_dda(t_dda *dda_n, t_ray *ray)
{
	dda_n->map.x = (int) ray->pos.x;
	dda_n->map.y = (int) ray->pos.y;
	dda_n->delta.x = sqrt(1 + (ray->dir.y * ray->dir.y)
							  / (ray->dir.x * ray->dir.x));
	dda_n->delta.y = sqrt(1 + (ray->dir.x * ray->dir.x)
							  / (ray->dir.y * ray->dir.y));
	dda_n->side.x = (ray->dir.x < 0)
					? (ray->pos.x - dda_n->map.x) * dda_n->delta.x
					: (dda_n->map.x + 1 - ray->pos.x) * dda_n->delta.x;
	dda_n->side.y = (ray->dir.y < 0)
					? (ray->pos.y - dda_n->map.y) * dda_n->delta.y
					: (dda_n->map.y + 1 - ray->pos.y) * dda_n->delta.y;
	dda_n->step.x = (ray->dir.x < 0) ? -1 : 1;
	dda_n->step.y = (ray->dir.y < 0) ? -1 : 1;
}