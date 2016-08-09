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
	int 		draw_start;
	int 		draw_end;

	line_height = (int) (WIN_SIZE_Y / perp_wall_dist);
	draw_start = -line_height / 2 + WIN_SIZE_Y / 2;
	draw_start = (draw_start < 0) ? 0 : draw_start;
	draw_end = line_height / 2 + WIN_SIZE_Y / 2;
	draw_end = (draw_end >= WIN_SIZE_Y) ? WIN_SIZE_Y - 1 : draw_end;
	//TODO USE YOUR OWN.
	SDL_RenderDrawLine(sdl->renderer, x, draw_start, x, draw_end);
}