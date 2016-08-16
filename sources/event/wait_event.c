//
//           :::      ::::::::
//         :+:      :+:    :+:     wait_event.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 13:59 by alegent
//

#include "wolf3d.h"

void 							wait_event(t_all *all)
{
	SDL_WaitEvent(all->sdl.event);
	if (all->sdl.event->type == SDL_QUIT)
		all->game.loop = FALSE;
	if (all->sdl.event->type == SDL_KEYDOWN)
		key_hook(all, all->sdl.event->key.keysym.sym);
	if (all->sdl.event->type == SDL_WINDOWEVENT)
		window_event(all);
}