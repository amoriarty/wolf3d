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

int 			game_loop(t_sdl *sdl)
{
	t_cam 		cam;

	init_cam(&cam);
	while (TRUE)
	{
		raycasting(sdl, &cam);
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
			return (SUCCESS);
		if (sdl->event->type == SDL_KEYDOWN)
		{
			if (sdl->event->key.keysym.sym == SDLK_ESCAPE)
				return (SUCCESS);
			key_hook(sdl->event->key.keysym.sym, &cam);
		}
	}
	return (FAILURE);
}