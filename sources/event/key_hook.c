/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:17:42 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:41:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** KEY_HOOK WILL CALL THE CORRECT FUNCTION ACCORDING TO THE KEY PRESSED
*/

void				key_hook(t_all *all, SDL_Keycode sym)
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
