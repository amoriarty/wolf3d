/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:18:35 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:45:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** INITIALIZE RAYON WITH CAMERA VARIABLES
*/

void			init_ray(t_all *all)
{
	all->game.ray.pos.x = all->game.cam.pos.x;
	all->game.ray.pos.y = all->game.cam.pos.y;
	all->game.ray.dir.x = all->game.cam.dir.x + all->game.cam.plane.x
		* (2 * all->game.iter.x / (double)all->sdl.win.width - 1);
	all->game.ray.dir.y = all->game.cam.dir.y + all->game.cam.plane.y
		* (2 * all->game.iter.x / (double)all->sdl.win.height - 1);
}
