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

int 			game_loop(t_all *all)
{
	//TODO PRELOAD TEXTURES
	all->sdl.wall = IMG_Load(PURPLESTONE_TEXTURE);
	all->sdl.floor = IMG_Load(GREYSTONE_TEXTURE);
	all->sdl.sky = IMG_Load(BLUESTONE_TEXTURE);
	while (all->game.loop)
	{
		raycasting(all);
		wait_event(all);
	}
	SDL_FreeSurface(all->sdl.wall);
	SDL_FreeSurface(all->sdl.floor);
	SDL_FreeSurface(all->sdl.sky);
	return (FAILURE);
}