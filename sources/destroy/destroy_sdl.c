/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:16:05 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:16:07 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					destroy_sdl(t_sdl *sdl)
{
	free(sdl->event);
	SDL_DestroyRenderer(sdl->win.renderer);
	SDL_DestroyWindow(sdl->win.window);
	SDL_Quit();
}
