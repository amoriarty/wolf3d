//
//           :::      ::::::::
//         :+:      :+:    :+:     dda.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 15:39 by alegent
//

#include "wolf3d.h"

/*
** AS "Digital Differential Analysis", Google it.
*/

int 			dda(t_dda *dda)
{
	int 		hit;
	int 		side;

	hit = FALSE;
	side = 0;
	while (!hit)
	{
		if (dda->side.x < dda->side.y)
		{
			dda->side.x += dda->delta.x;
			dda->map.x += dda->step.x;
			side = 0;
		}
		else
		{
			dda->side.y += dda->delta.y;
			dda->map.y += dda->step.y;
			side = 1;
		}
		hit = (map_value((int)dda->map.x, (int)dda->map.y)) ? 1 : 0;
	}
	return (side);
}