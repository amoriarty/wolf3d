//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_vert.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 05/08/2016 17:46 by alegent
//

#include "wolf3d.h"

/*
** TO DRAW A VERTICAL
*/

void 			draw_vert(SDL_Renderer *r, int x, int y1, int y2)
{
	if (y1 < y2)
		while (y1 <= y2)
			SDL_RenderDrawPoint(r, x, y1++);
	else
		while (y1 >= y2)
			SDL_RenderDrawPoint(r, x, y1--);
}