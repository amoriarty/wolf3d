/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:16:17 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 15:42:12 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "floor.h"

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

static void				ft_norme(t_all *all, t_floor *fall)
{
	while (++(all->game.iter.y) < all->sdl.win.height)
	{
		fall->current_dist =
			all->sdl.win.height / (2 * all->game.iter.y - all->sdl.win.height);
		fall->weight = (fall->current_dist - fall->dist_player)
			/ (fall->dist_wall - fall->dist_player);
		fall->current_floor.x = fall->weight * fall->floor.x
			+ (1 - fall->weight) * all->game.cam.pos.x;
		fall->current_floor.y = fall->weight * fall->floor.y
			+ (1 - fall->weight) * all->game.cam.pos.y;
		fall->texture.x = (int)(fall->current_floor.x * all->sdl.floor->w)
			% (int)all->sdl.floor->w;
		fall->texture.y = (int)(fall->current_floor.y * all->sdl.floor->h)
			% (int)all->sdl.floor->h;
		draw_floor_texture(all, &fall->texture);
		draw_sky_texture(all, &fall->texture);
	}
}

void					draw_floor(t_all *all)
{
	t_floor				fall;

	if (!(all->game.dda.s) && all->game.ray.dir.x > 0)
	{
		fall.floor.x = all->game.dda.map.x;
		fall.floor.y = all->game.dda.map.y + all->game.dda.wall_x;
	}
	else if (!(all->game.dda.s) && all->game.ray.dir.x < 0)
	{
		fall.floor.x = all->game.dda.map.x + 1;
		fall.floor.y = all->game.dda.map.y + all->game.dda.wall_x;
	}
	else if (all->game.dda.s && all->game.ray.dir.y > 0)
	{
		fall.floor.x = all->game.dda.map.x + all->game.dda.wall_x;
		fall.floor.y = all->game.dda.map.y;
	}
	else
	{
		fall.floor.x = all->game.dda.map.x + all->game.dda.wall_x;
		fall.floor.y = all->game.dda.map.y + 1;
	}
	fall.dist_wall = all->game.dda.pwd;
	fall.dist_player = 0;
	ft_norme(all, &fall);
}
