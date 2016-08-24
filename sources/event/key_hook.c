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
		move_up(&(all->game.cam));
	else if (sym == SDLK_DOWN || sym == SDLK_s)
		move_down(&(all->game.cam));
	else if (sym == SDLK_LEFT || sym == SDLK_a)
		rotate_left(&(all->game.cam));
	else if (sym == SDLK_RIGHT || sym == SDLK_d)
		rotate_right(&(all->game.cam));
	else if (sym == SDLK_ESCAPE)
		all->game.loop = FALSE;
	raycasting(all);
}