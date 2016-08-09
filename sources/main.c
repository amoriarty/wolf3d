//
//           :::      ::::::::
//         :+:      :+:    :+:     main.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 04/08/2016 15:16 by alegent
//

#include "wolf3d.h"

static int 					dda(t_coor *side_dist, t_coor *map, t_coor *step, t_coor *delta)
{
	int 					hit;
	int 					side;

	hit = FALSE;
	side = 0;
	while (!hit)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta->x;
			map->x += step->x;
			side = 0;
		}
		else
		{
			side_dist->y += delta->y;
			map->y += step->y;
			side = 1;
		}
		hit = (map_value((int)map->x, (int)map->y)) ? 1 : 0;
	}
	return (side);
}

static void 				draw_wall(t_sdl *sdl, int x, double perp_wall_dist)
{
	int 					lineHeight;
	int 					drawStart;
	int 					drawEnd;

	//Calculate height of line to draw on screen
	lineHeight = (int) (WIN_SIZE_Y / perp_wall_dist);

	//calculate lowest and highest pixel to fill in current stripe
	drawStart = -lineHeight / 2 + WIN_SIZE_Y / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_SIZE_Y / 2;
	if (drawEnd >= WIN_SIZE_Y)
		drawEnd = WIN_SIZE_Y - 1;

	//TODO USE YOUR OWN.
	SDL_RenderDrawLine(sdl->renderer, x, drawStart, x, drawEnd);
}

static void 				raycasting(t_sdl *sdl, t_cam *camera)
{
	int 					x;
	double 					cameraX;
	t_coor					ray_pos;
	t_coor					ray_dir;
	t_coor					map;
	t_coor					side_dist;
	t_coor					delta;
	double 					perpWallDist;
	t_coor					step;

	// THE TROUBLE CONTINUE HERE
	x = -1;
	while (++x < WIN_SIZE_X)
	{
		cameraX = 2 * x / (double) WIN_SIZE_X - 1;
		ray_pos.x = camera->position.x;
		ray_pos.y = camera->position.y;
		ray_dir.x = camera->direction.x + camera->plane.x * cameraX;
		ray_dir.y = camera->direction.y + camera->plane.y * cameraX;
		map.x = (int) ray_pos.x;
		map.y = (int) ray_pos.y;
		delta.x = sqrt(1 + (ray_dir.y * ray_dir.y) / (ray_dir.x * ray_dir.x));
		delta.y = sqrt(1 + (ray_dir.x * ray_dir.x) / (ray_dir.y * ray_dir.y));
		side_dist.x = (ray_dir.x < 0) ? (ray_pos.x - map.x) * delta.x
									  : (map.x + 1 - ray_pos.x) * delta.x;
		side_dist.y = (ray_dir.y < 0) ? (ray_pos.y - map.y) * delta.y
									  : (map.y + 1 - ray_pos.y) * delta.y;
		step.x = (ray_dir.x < 0) ? -1 : 1;
		step.y = (ray_dir.y < 0) ? -1 : 1;

		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (!dda(&side_dist, &map, &step, &delta))
			perpWallDist = (map.x - ray_pos.x + (1 - step.x) / 2) / ray_dir.x;
		else
			perpWallDist = (map.y - ray_pos.y + (1 - step.y) / 2) / ray_dir.y;

		draw_wall(sdl, x, perpWallDist);
	}
	//THE TROUBLE FINISH HERE
}

//TEMPORARY LOOP
static int game_loop(t_sdl *sdl)
{
	t_cam camera;

	init_cam(&camera);
	while (TRUE) // SO WHILE TRUE ...
	{
		draw_background(sdl);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 0, 0);
		raycasting(sdl, &camera);
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
			return (SUCCESS);
		//TODO KEY REPEAT

		// THE TROUBLE BEGIN HERE
		if (sdl->event->type == SDL_KEYDOWN)
		{

			double oldDirX, oldPlaneX;
			switch (sdl->event->key.keysym.sym)
			{
				case (SDLK_UP):
					if (!map_value((int) (camera.position.x +
										  camera.direction.x * MOVE_SPEED),
								   (int) camera.position.y))
						camera.position.x += camera.direction.x * MOVE_SPEED;
					if (!map_value((int) camera.position.x,
								   (int) (camera.position.y +
										  camera.direction.y * MOVE_SPEED)))
						camera.position.y += camera.direction.y * MOVE_SPEED;
					break;
				case (SDLK_DOWN):
					if (!map_value((int) (camera.position.x -
										  camera.direction.x * MOVE_SPEED),
								   (int) camera.position.y))
						camera.position.x -= camera.direction.x * MOVE_SPEED;
					if (!map_value((int) camera.position.x,
								   (int) (camera.position.y -
										  camera.direction.y * MOVE_SPEED)))
						camera.position.y -= camera.direction.y * MOVE_SPEED;
					break;
				case (SDLK_RIGHT):
					oldDirX = camera.direction.x;
					camera.direction.x =
							camera.direction.x * cos(-ROTATE_SPEED) -
							camera.direction.y * sin(-ROTATE_SPEED);
					camera.direction.y = oldDirX * sin(-ROTATE_SPEED) +
										 camera.direction.y *
										 cos(-ROTATE_SPEED);
					oldPlaneX = camera.plane.x;
					camera.plane.x = camera.plane.x * cos(-ROTATE_SPEED) -
									 camera.plane.y * sin(-ROTATE_SPEED);
					camera.plane.y = oldPlaneX * sin(-ROTATE_SPEED) +
									 camera.plane.y * cos(-ROTATE_SPEED);
					break;
				case (SDLK_LEFT):
					oldDirX = camera.direction.x;
					camera.direction.x =
							camera.direction.x * cos(ROTATE_SPEED) -
							camera.direction.y * sin(ROTATE_SPEED);
					camera.direction.y = oldDirX * sin(ROTATE_SPEED) +
										 camera.direction.y * cos(ROTATE_SPEED);
					oldPlaneX = camera.plane.x;
					camera.plane.x = camera.plane.x * cos(ROTATE_SPEED) -
									 camera.plane.y * sin(ROTATE_SPEED);
					camera.plane.y = oldPlaneX * sin(ROTATE_SPEED) +
									 camera.plane.y * cos(ROTATE_SPEED);
					break;
			}
		}
		SDL_RenderPresent(sdl->renderer);
		// THE TROUBLE FINISH HERE
	}
	return (FAILURE);
}

/*
** SETTING SDL STRUCTURE
** (OPEN WINDOW, SETTING TITLE, SETTING RENDERER,
** ALLOCATE SDL_EVENTS AND FINALLY GIVE THE STRUCTURE TO GAME FUNCTION)
*/

int main(void)
{
	t_sdl sdl;

	if (SDL_Init(SDL_INIT_VIDEO) != -1)
	{
		SDL_CreateWindowAndRenderer(
				WIN_SIZE_X, WIN_SIZE_Y, 0, &sdl.window, &sdl.renderer);
		if (sdl.window)
		{
			SDL_SetWindowTitle(sdl.window, WIN_TITLE);
			if ((sdl.event = (SDL_Event *) malloc(sizeof(SDL_Event))))
				game_loop(&sdl); //TODO TEMPORARY LOOP
			free(sdl.event);
			SDL_DestroyRenderer(sdl.renderer);
			SDL_DestroyWindow(sdl.window);
			SDL_Quit();
			return (EXIT_SUCCESS);
		}
	}
	SDL_Quit();
	return (EXIT_FAILURE);
}