/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:16:17 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:41:14 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void				draw_sky_texture(t_all *all, t_coor *texture)
{
	Uint8				pxl[4];

	SDL_LockSurface(all->sdl.sky);
	SDL_GetRGBA(get_pixel(all->sdl.sky, (int)texture->x, (int)texture->y),
				all->sdl.sky->format,
				&(pxl[0]), &(pxl[1]), &(pxl[2]), &(pxl[3]));
	SDL_UnlockSurface(all->sdl.sky);
	SDL_SetRenderDrawColor(all->sdl.win.renderer,
			pxl[0], pxl[1], pxl[2], pxl[3]);
	SDL_RenderDrawPoint(all->sdl.win.renderer,
			(int)all->game.iter.x,
			all->sdl.win.height - (int)all->game.iter.y);
}

static void				draw_floor_texture(t_all *all, t_coor *texture)
{
	Uint8				pxl[4];

	SDL_LockSurface(all->sdl.floor);
	SDL_GetRGBA(get_pixel(all->sdl.floor, (int)texture->x, (int)texture->y),
			all->sdl.floor->format, &(pxl[0]), &(pxl[1]), &(pxl[2]), &(pxl[3]));
	SDL_UnlockSurface(all->sdl.floor);
	SDL_SetRenderDrawColor(all->sdl.win.renderer,
			pxl[0], pxl[1], pxl[2], pxl[3]);
	SDL_RenderDrawPoint(all->sdl.win.renderer,
			(int)all->game.iter.x, (int)all->game.iter.y);
}

void					draw_floor(t_all *all)
{
	t_coor				floor;
	double				dist_wall;
	double				dist_player;
	double				current_dist;
	double				weight;
	t_coor				current_floor;
	t_coor				texture;

	if (!(all->game.dda.s) && all->game.ray.dir.x > 0)
	{
		floor.x = all->game.dda.map.x;
		floor.y = all->game.dda.map.y + all->game.dda.wall_x;
	}
	else if (!(all->game.dda.s) && all->game.ray.dir.x < 0)
	{
		floor.x = all->game.dda.map.x + 1;
		floor.y = all->game.dda.map.y + all->game.dda.wall_x;
	}
	else if (all->game.dda.s && all->game.ray.dir.y > 0)
	{
		floor.x = all->game.dda.map.x + all->game.dda.wall_x;
		floor.y = all->game.dda.map.y;
	}
	else
	{
		floor.x = all->game.dda.map.x + all->game.dda.wall_x;
		floor.y = all->game.dda.map.y + 1;
	}
	dist_wall = all->game.dda.pwd;
	dist_player = 0;
	while (++(all->game.iter.y) < all->sdl.win.height)
	{
		current_dist = all->sdl.win.height / (2 * all->game.iter.y - all->sdl.win.height);
		weight = (current_dist - dist_player) / (dist_wall - dist_player);
		current_floor.x = weight * floor.x + (1 - weight) * all->game.cam.pos.x;
		current_floor.y = weight * floor.y + (1 - weight) * all->game.cam.pos.y;
		texture.x = (int)(current_floor.x * all->sdl.floor->w) % (int)all->sdl.floor->w;
		texture.y = (int)(current_floor.y * all->sdl.floor->h) % (int)all->sdl.floor->h;
		draw_floor_texture(all, &texture);
		draw_sky_texture(all, &texture);
	}
}
