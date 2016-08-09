//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_background.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 12:33 by alegent
//

#include "wolf3d.h"

/*
** DRAW ALL PIXEL IN COLOR DEFINE IN BACKGROUND_COLOR
*/

void				draw_background(t_sdl *sdl)
{
	int 				x;
	int 				y;

	x = -1;
	SDL_SetRenderDrawColor(sdl->renderer, BACKGROUND_COLOR);
	while (++x < WIN_SIZE_X)
	{
		y = -1;
		while (++y < WIN_SIZE_Y)
			SDL_RenderDrawPoint(sdl->renderer, x, y);
	}
}