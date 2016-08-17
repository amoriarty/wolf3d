//
//           :::      ::::::::
//         :+:      :+:    :+:     key_hook.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 16:48 by alegent
//

#include "wolf3d.h"

/*
** KEY_HOOK WILL CALL THE CORRECT FUNCTION ACCORDING TO THE KEY PRESSED
*/

void 			key_hook(t_all *all, SDL_Keycode sym)
{
	if (sym == SDLK_UP || sym == SDLK_w)
		all->game.arrow[UP] = TRUE;
	else if (sym == SDLK_DOWN || sym == SDLK_s)
		all->game.arrow[DOWN] = TRUE;
	else if (sym == SDLK_LEFT || sym == SDLK_a)
		all->game.arrow[LEFT] = TRUE;
	else if (sym == SDLK_RIGHT || sym == SDLK_d)
		all->game.arrow[RIGHT] = TRUE;
	else if (sym == SDLK_ESCAPE)
		all->game.loop = FALSE;
	check_move(all);
}