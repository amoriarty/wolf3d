/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:18:46 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:18:59 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool					init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_FLAG) != ERROR)
	{
		if (init_window(&(sdl->win)))
		{
			if ((sdl->event = (SDL_Event *)malloc(sizeof(SDL_Event))))
				return (TRUE);
			SDL_DestroyRenderer(sdl->win.renderer);
			SDL_DestroyWindow(sdl->win.window);
		}
		SDL_Quit();
	}
	return (FALSE);
}
