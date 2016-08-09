//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_vertical.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 05/08/2016 17:46 by alegent
//

#include "wolf3d.h"

//TODO REAL VERTICAL DRAWING FUNCTION
void 				draw_vertical(SDL_Renderer *renderer, int x, int draw_start, int draw_end)
{
	if (draw_start < draw_end)
		while (draw_start <= draw_end)
			SDL_RenderDrawPoint(renderer, x, draw_start++);
	else
		while (draw_start >= draw_end)
			SDL_RenderDrawPoint(renderer, x, draw_start--);
}