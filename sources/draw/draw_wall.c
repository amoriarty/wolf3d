//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_wall.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 15:18 by alegent
//

#include "wolf3d.h"

/*
** CALCULATE THE WALL HEIGHT AT X COORDINATE AND RENDER IT
*/

static void 	draw_texture(t_all *all, t_coor *texture)
{
	Uint8 		pxl[4];

	texture->y = (all->game.iter.y * 2 - WIN_SIZE_Y + all->game.dda.line_height)
				 * (all->sdl.wall->h / 2) / all->game.dda.line_height;
	SDL_LockSurface(all->sdl.wall);
	SDL_GetRGBA(get_pixel(all->sdl.wall, (int)texture->x, (int)texture->y),
				all->sdl.wall->format,
				&(pxl[0]), &(pxl[1]), &(pxl[2]), &(pxl[3]));
	SDL_UnlockSurface(all->sdl.wall);
	SDL_SetRenderDrawColor(all->sdl.win.renderer,
						   pxl[0], pxl[1], pxl[2], pxl[3]);
	SDL_RenderDrawPoint(all->sdl.win.renderer,
						(int)all->game.iter.x,
						(int)all->game.iter.y);
}

void 			draw_wall(t_all *all)
{
	t_coor		texture;

	all->game.dda.pwd = (!(all->game.dda.s))
		  ? (all->game.dda.map.x - all->game.ray.pos.x +
					(1 - all->game.dda.step.x) / 2) / all->game.ray.dir.x
		  : (all->game.dda.map.y - all->game.ray.pos.y +
					(1 - all->game.dda.step.y) / 2) / all->game.ray.dir.y;
	all->game.dda.line_height = (int) (WIN_SIZE_Y / all->game.dda.pwd);
	all->game.dda.start = -all->game.dda.line_height / 2 + WIN_SIZE_Y / 2;
	all->game.dda.start = (all->game.dda.start < 0) ? 0 : all->game.dda.start;
	all->game.dda.end = all->game.dda.line_height / 2 + WIN_SIZE_Y / 2;
	all->game.dda.end = (all->game.dda.end >= WIN_SIZE_Y)
						? WIN_SIZE_Y - 1 : all->game.dda.end;
	all->game.dda.wall_x = (!(all->game.dda.s))
			   ? all->game.ray.pos.y + all->game.dda.pwd * all->game.ray.dir.y
			   : all->game.ray.pos.x + all->game.dda.pwd * all->game.ray.dir.x;
	all->game.dda.wall_x -= floor(all->game.dda.wall_x);
	texture.x = (int)(all->game.dda.wall_x * all->sdl.wall->w);
	if (!(all->game.dda.s) && all->game.ray.dir.x > 0)
		texture.x = all->sdl.wall->w - texture.x - 1;
	if (!(all->game.dda.s) && all->game.ray.dir.x < 0)
		texture.x = all->sdl.wall->w - texture.x - 1;
	all->game.iter.y = all->game.dda.start - 1;
	while (++(all->game.iter.y) < all->game.dda.end)
		draw_texture(all, &texture);
}