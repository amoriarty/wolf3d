//
//           :::      ::::::::
//         :+:      :+:    :+:     get_pixel.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 10/08/2016 10:26 by alegent
//

#include "wolf3d.h"

Uint32				get_pixel(SDL_Surface *surface, int x, int y)
{
	int				bpp;
	Uint8			*p;

	bpp = surface->format->BitsPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 8)
		return (*p);
	else if (bpp == 16)
		return (*(Uint16 *)p);
	else if (bpp == 24)
	{
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
	}
	else if (bpp == 32)
		return (*(Uint32 *)p);
	return (0);
}