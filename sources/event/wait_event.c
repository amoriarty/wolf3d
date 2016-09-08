/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:17:48 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:42:32 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				wait_event(t_all *all)
{
	SDL_WaitEvent(all->sdl.event);
	if (all->sdl.event->type == SDL_QUIT)
		all->game.loop = FALSE;
	if (all->sdl.event->type == SDL_KEYDOWN)
		key_hook(all, all->sdl.event->key.keysym.sym);
}
