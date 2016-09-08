/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:20:10 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:50:12 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** MY RAYCASTING ALGORITHM, MINIMIZE TO FUNCTIONS CALLED
*/

void					raycasting(t_all *all)
{
	all->game.iter.x = -1;
	while (++(all->game.iter.x) < all->sdl.win.width)
	{
		init_ray(all);
		init_dda(&(all->game.dda), &(all->game.ray));
		all->game.dda.s = dda(&(all->game.dda));
		draw_wall(all);
		draw_floor(all);
	}
	SDL_RenderPresent(all->sdl.win.renderer);
}
