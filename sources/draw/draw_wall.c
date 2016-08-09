//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_wall.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 15:18 by alegent
//

#include "wolf3d.h"

/*
** CALCULATE THE WALL HEIGHT AT X COORDINATE AND RENDER IT
*/

void 			draw_wall(t_sdl *sdl, int x, double perp_wall_dist)
{
	int 		line_height;
	int 		start;
	int 		end;

	line_height = (int) (WIN_SIZE_Y / perp_wall_dist);
	start = -line_height / 2 + WIN_SIZE_Y / 2;
	start = (start < 0) ? 0 : start;
	end = line_height / 2 + WIN_SIZE_Y / 2;
	end = (end >= WIN_SIZE_Y) ? WIN_SIZE_Y - 1 : end;
	draw_vert(sdl->renderer, x, start, end);
}