//
//           :::      ::::::::
//         :+:      :+:    :+:     init_window.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 13:38 by alegent
//

#include "wolf3d.h"

t_bool					init_window(t_win *win)
{
	win->width = WIN_WIDHT;
	win->height = WIN_HEIGHT;
	SDL_CreateWindowAndRenderer(
			win->width, win->height, 0, &(win->window), &(win->renderer));
	if (!(win->window))
		return (FALSE);
	SDL_SetWindowTitle(win->window, WIN_TITLE);
	return (TRUE);
}
