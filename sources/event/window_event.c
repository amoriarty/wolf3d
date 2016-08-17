//
//           :::      ::::::::
//         :+:      :+:    :+:     window_event.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 17:29 by alegent
//

#include "wolf3d.h"

void 					window_event(t_all *all)
{
	if (all->sdl.event->window.event == SDL_WINDOWEVENT_RESIZED)
	{
		all->sdl.win.width = all->sdl.event->window.data1;
		all->sdl.win.height = all->sdl.event->window.data2;
		raycasting(all);
	}
}