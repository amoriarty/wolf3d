/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:08 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:43:16 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool					init_window(t_win *win)
{
	win->width = WIN_WIDHT;
	win->height = WIN_HEIGHT;
	SDL_CreateWindowAndRenderer(
			win->width, win->height,
			WIN_FLAG, &(win->window), &(win->renderer));
	if (!(win->window))
		return (FALSE);
	SDL_SetWindowTitle(win->window, WIN_TITLE);
	return (TRUE);
}
