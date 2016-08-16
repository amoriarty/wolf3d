//
//           :::      ::::::::
//         :+:      :+:    :+:     draw_floor.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 12/08/2016 14:25 by alegent
//

#include "wolf3d.h"

static void 	draw_texture(t_sdl *sdl, t_coor *t, int l, t_coor *pos)
{
	Uint8 		pxl[4];

	t->y = (pos->y * 2 - WIN_SIZE_Y + l) * (sdl->floor->h / 2) / l;
	SDL_LockSurface(sdl->floor);
	SDL_GetRGBA(get_pixel(sdl->floor, (int)t->x, (int)t->y),
				sdl->floor->format, &(pxl[0]), &(pxl[1]), &(pxl[2]), &(pxl[3]));
	SDL_UnlockSurface(sdl->floor);
	SDL_SetRenderDrawColor(sdl->renderer, pxl[0], pxl[1], pxl[2], pxl[3]);
	SDL_RenderDrawPoint(sdl->renderer, (int)pos->x, (int)pos->y);
}

void 			draw_floor(t_sdl *sdl, int x, t_dda *dda_n, t_ray *ray)
{
	int 		data[3];
	double 		ddata[2];
	t_coor		texture;
	t_coor		pos;
	t_coor		f;

	pos.x = x;



	//PWD CALCUL
	ddata[0] = (!dda_n->s)
		  ? (dda_n->map.x - ray->pos.x + (1 - dda_n->step.x) / 2) / ray->dir.x
		  : (dda_n->map.y - ray->pos.y + (1 - dda_n->step.y) / 2) / ray->dir.y;

	//LINE HEIGHT
	data[0] = (int) (WIN_SIZE_Y / ddata[0]);

	//START
	data[1] = -data[0] / 2 + WIN_SIZE_Y / 2;
	data[1] = (data[1] < 0) ? 0 : data[1];

	//END
	data[2] = data[0] / 2 + WIN_SIZE_Y / 2;
	data[2] = (data[2] >= WIN_SIZE_Y) ? WIN_SIZE_Y - 1 : data[2];

	//WALL X
	ddata[1] = (!dda_n->s) ? ray->pos.x + ddata[0] * ray->dir.y
						   : ray->pos.x + ddata[0] * ray->dir.x;
	ddata[1] -= floor(ddata[1]);

	//FLOOR DIRECTIONS
	if (dda_n->s == 0 && ray->dir.x > 0)
	{
		f.x = dda_n->map.x;
		f.y = dda_n->map.y;
	}
	else if (dda_n->s == 0 && ray->dir.x < 0)
	{
		f.x = dda_n->map.x + 1;
		f.y = dda_n->map.y + ddata[1];
	}
	else if (dda_n->s && ray->dir.y > 0)
	{
		f.x = dda_n->map.x + ddata[1];
		f.y = dda_n->map.y;
	}
	else
	{
		f.x = dda_n->map.x + ddata[1];
		f.y = dda_n->map.y + 1;
	}

	//TEXTURE COORDINATE
	texture.x = (int)(ddata[1] * sdl->floor->w);
	if (!dda_n->s && ray->dir.x > 0)
		texture.x = sdl->floor->w - texture.x - 1;
	if (dda_n->s && ray->dir.x < 0)
		texture.x = sdl->floor->w - texture.x - 1;

	//FOR EVERY Y, DRAW TEXTURE
	pos.y = data[1] - 1;
	while (++(pos.y) < data[2])
		draw_texture(sdl, &texture, data[0], &pos);
}