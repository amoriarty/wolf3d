//
//           :::      ::::::::
//         :+:      :+:    :+:     keyup_hook.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 17/08/2016 16:06 by alegent
//

#include "wolf3d.h"

void 			keyup_hook(t_all *all, SDL_Keycode sym)
{
	if (sym == SDLK_UP || sym == SDLK_w)
		all->game.arrow[UP] = FALSE;
	else if (sym == SDLK_DOWN || sym == SDLK_s)
		all->game.arrow[DOWN] = FALSE;
	else if (sym == SDLK_LEFT || sym == SDLK_a)
		all->game.arrow[LEFT] = FALSE;
	else if (sym == SDLK_RIGHT || sym == SDLK_d)
		all->game.arrow[RIGHT] = FALSE;
	check_move(all);
}