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

void 					draw_vert(SDL_Renderer *r, int x, int y0, int y1)
{
	(void)r;
	(void)x;
	(void)y0;
	(void)y1;
	/*
	SDL_SetRenderDrawColor(r, 255, 255, 255, 0);
	if (y0 < y1)
		while (y0 <= y1)
			SDL_RenderDrawPoint(r, x, y0++);
	else
		while (y0 >= y1)
			SDL_RenderDrawPoint(r, x, y0--);
	*/
	/*
	static SDL_Surface	*texture;
	Uint8 				rgb[4];
	Uint32 				pixel;

	if (!texture)
		texture = IMG_Load(GREYSTONE_TEXTURE);
	y0--;
	while (++y0 < y1)
	{
		//LOCK SURFACE, GET PIXEL, UNLOCK
		SDL_LockSurface(texture);
		//pixel = get_pixel(texture, texU, texV);
		SDL_UnlockSurface(texture);

		//CONVERT Uint32 PIXEL IN RGBA VALUE
		SDL_GetRGBA(pixel, texture->format,
					&(rgb[0]), &(rgb[1]), &(rgb[2]), &(rgb[3]));

		//DRAW POINT TO THE SCREEN
		SDL_SetRenderDrawColor(r, rgb[0], rgb[1], rgb[2], rgb[3]);
		SDL_RenderDrawPoint(r, x, y0);
	}
	*/
}