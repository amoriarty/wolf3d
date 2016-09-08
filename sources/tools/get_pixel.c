/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:20:36 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:53:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32				get_pixel(SDL_Surface *surface, int x, int y)
{
	Uint8			*p;

	p = (Uint8 *)surface->pixels + y * surface->pitch
		+ x * surface->format->BytesPerPixel;
	if (surface->format->BytesPerPixel == 1)
		return (*p);
	else if (surface->format->BytesPerPixel == 2)
		return (*(Uint16 *)p);
	else if (surface->format->BytesPerPixel == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (surface->format->BytesPerPixel == 4)
		return (*(Uint32 *)p);
	return (0);
}
