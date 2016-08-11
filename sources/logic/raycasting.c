//
//           :::      ::::::::
//         :+:      :+:    :+:     raycasting.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 16:00 by alegent
//

#include "wolf3d.h"

/*
** MY RAYCASTING ALGORITHM, MINIMIZE TO FUNCTIONS CALLED
*/

void 			raycasting(t_sdl *sdl, t_cam *cam)
{
	int 		x;
	int 		side;
	t_ray		ray;
	t_dda		dda_n;
	double 		pwd;
	//TODO DEGAGER TEXTURE
	SDL_Surface	*texture;

	x = -1;
	draw_background(sdl);
	//TODO DEGAGER TEXTURE
	if (!(texture = IMG_Load(GREYSTONE_TEXTURE)))
		return ;
	while (++x < WIN_SIZE_X)
	{
		init_ray(&ray, cam, x);
		init_dda(&dda_n, &ray);
		side = dda(&dda_n);
		pwd = (!side)
			  ? (dda_n.map.x - ray.pos.x + (1 - dda_n.step.x) / 2) / ray.dir.x
			  : (dda_n.map.y - ray.pos.y + (1 - dda_n.step.y) / 2) / ray.dir.y;
		//draw_wall(sdl, x, pwd);

		//TROUBLE HERE
		int 		line_height;
		int 		start;
		int 		end;

		line_height = (int) (WIN_SIZE_Y / pwd);
		start = -line_height / 2 + WIN_SIZE_Y / 2;
		start = (start < 0) ? 0 : start;
		end = line_height / 2 + WIN_SIZE_Y / 2;
		end = (end >= WIN_SIZE_Y) ? WIN_SIZE_Y - 1 : end;

		//TROUBLE REALLY BEGIN HERE !
		double		wall_x;
		int			tex_x;

		wall_x = (!side) ? ray.pos.x + pwd * ray.dir.y
						 : ray.pos.x + pwd * ray.dir.x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * texture->w);
		if (!side && ray.dir.x > 0)
			tex_x = texture->w - tex_x - 1;
		if (side && ray.dir.x < 0)
			tex_x = texture->w - tex_x - 1;
		for (int y = start; y < end; y++)
		{
			int 		tex_y;
			Uint32		color;
			Uint8 		pxl[4];

			tex_y = (y * 2 - WIN_SIZE_Y + line_height) * 32 / line_height;
			SDL_LockSurface(texture);
			color = get_pixel(texture, tex_x, tex_y);
			SDL_UnlockSurface(texture);
			SDL_GetRGBA(color, texture->format, &(pxl[0]), &(pxl[1]), &(pxl[2]), &(pxl[3]));
			SDL_SetRenderDrawColor(sdl->renderer, pxl[0], pxl[1], pxl[2], pxl[3]);
			SDL_RenderDrawPoint(sdl->renderer, x, y);
		}
		//END TROUBLE
	}
	SDL_RenderPresent(sdl->renderer);
	SDL_FreeSurface(texture);
}