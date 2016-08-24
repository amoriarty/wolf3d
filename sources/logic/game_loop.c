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
	all->sdl.wall = SDL_LoadBMP(WALL_TEXTURE_PATH);
	all->sdl.floor = SDL_LoadBMP(FLOOR_TEXTURE_PATH);
	all->sdl.sky = SDL_LoadBMP(SKY_TEXTURE_PATH);
	raycasting(all);
	while (all->game.loop)
		wait_event(all);
	SDL_FreeSurface(all->sdl.wall);
	SDL_FreeSurface(all->sdl.floor);
	SDL_FreeSurface(all->sdl.sky);
	return (FAILURE);
}