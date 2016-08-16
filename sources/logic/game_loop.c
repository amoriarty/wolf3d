//
//           :::      ::::::::
//         :+:      :+:    :+:     game_loop.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 17:17 by alegent
//

#include "wolf3d.h"

/*
** GAME LOOP
*/

void 			load_texture(t_sdl *sdl)
{
	sdl->wall = IMG_Load(GREYSTONE_TEXTURE);
	sdl->floor = IMG_Load(PURPLESTONE_TEXTURE);
}

void 			unload_texture(t_sdl *sdl)
{
	SDL_FreeSurface(sdl->wall);
	SDL_FreeSurface(sdl->floor);
}

int 			game_loop(t_sdl *sdl)
{
	t_cam 		cam;

	init_cam(&cam);
	load_texture(sdl);
	while (TRUE)
	{
		raycasting(sdl, &cam);
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
		{
			unload_texture(sdl);
			return (SUCCESS);
		}
		if (sdl->event->type == SDL_KEYDOWN)
		{
			if (sdl->event->key.keysym.sym == SDLK_ESCAPE)
			{
				unload_texture(sdl);
				return (SUCCESS);
			}
			key_hook(sdl->event->key.keysym.sym, &cam);
		}
	}
	return (FAILURE);
}