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
	/*
	SDL_SetRenderDrawColor(r, 255, 255, 255, 0);
	if (y0 < y1)
		while (y0 <= y1)
			SDL_RenderDrawPoint(r, x, y0++);
	else
		while (y0 >= y1)
			SDL_RenderDrawPoint(r, x, y0--);
	*/
	static SDL_Surface	*texture;
	int 				height;
	double 				ratio;
	double 				v;
	int 				texV;
	int 				texU;
	Uint8 				rgb[4];
	Uint32 				pixel;

	if (!texture)
		texture = IMG_Load(GREYSTONE_TEXTURE);
	if (y0 < y1)
		height = y1 - y0;
	else
		height = y0 - y1;
	ratio = texture->h - height;
	v = 0;
	y0--;
	while (++y0 < y1)
	{
		texV = (int)v & texture->h - 1;
		texU = x & texture->h - 1;
		SDL_LockSurface(texture);
		pixel = get_pixel(texture, texU, texV);
		SDL_UnlockSurface(texture);
		SDL_GetRGBA(pixel, texture->format,
					&(rgb[0]), &(rgb[1]), &(rgb[2]), &(rgb[3]));
		SDL_SetRenderDrawColor(r, rgb[0], rgb[1], rgb[2], rgb[3]);
		SDL_RenderDrawPoint(r, x, y0);
		v += ratio;
	}
}