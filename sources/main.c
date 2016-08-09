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


//TEMPORARY LOOP
static int 				game_loop(t_sdl *sdl)
{
	t_cam				camera;

	init_cam(&camera);
	while (TRUE) // SO WHILE TRUE ...
	{
		draw_background(sdl);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 0, 0);// (SET GREEN COLOR)

		// THE TROUBLE CONTINUE HERE
		for (int x = 0; x < WIN_SIZE_X; x++)
		{
			double cameraX = 2 * x / (double)WIN_SIZE_X - 1;
			double rayPosX = camera.position.x, rayPosY = camera.position.y;
			double rayDirX = camera.direction.x + camera.plane.x * cameraX;
			double rayDirY = camera.direction.y + camera.plane.y * cameraX;
			int mapX = (int)rayPosX, mapY = (int)rayPosY;
			double sideDistX, sideDistY;
			double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
			double perpWallDist;
			int stepX, stepY, hit = 0, side;

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (map_value(mapX, mapY) > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(WIN_SIZE_Y / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + WIN_SIZE_Y / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + WIN_SIZE_Y / 2;
			if (drawEnd >= WIN_SIZE_Y)
				drawEnd = WIN_SIZE_Y - 1;

			//TODO USE YOUR OWN.
			SDL_RenderDrawLine(sdl->renderer, x, drawStart, x, drawEnd);
		}
		//THE TROUBLE FINISH HERE

		// SDL EVENT WAITING HERE
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
			return (SUCCESS);

		// THE TROUBLE BEGIN HERE
		if (sdl->event->type == SDL_KEYDOWN)
		{
			double oldDirX, oldPlaneX;
			switch (sdl->event->key.keysym.sym)
			{
				case (SDLK_UP):
					if (!map_value((int)(camera.position.x + camera.direction.x * MOVE_SPEED), (int)camera.position.y))
						camera.position.x += camera.direction.x * MOVE_SPEED;
					if (!map_value((int)camera.position.x, (int)(camera.position.y + camera.direction.y * MOVE_SPEED)))
						camera.position.y += camera.direction.y * MOVE_SPEED;
					break ;
				case (SDLK_DOWN):
					if (!map_value((int)(camera.position.x - camera.direction.x * MOVE_SPEED), (int)camera.position.y))
						camera.position.x -= camera.direction.x * MOVE_SPEED;
					if (!map_value((int)camera.position.x, (int)(camera.position.y - camera.direction.y * MOVE_SPEED)))
						camera.position.y -= camera.direction.y * MOVE_SPEED;
					break ;
				case (SDLK_RIGHT):
					oldDirX = camera.direction.x;
					camera.direction.x = camera.direction.x * cos(-ROTATE_SPEED) - camera.direction.y * sin(-ROTATE_SPEED);
					camera.direction.y = oldDirX * sin(-ROTATE_SPEED) + camera.direction.y * cos(-ROTATE_SPEED);
					oldPlaneX = camera.plane.x;
					camera.plane.x = camera.plane.x * cos(-ROTATE_SPEED) - camera.plane.y * sin(-ROTATE_SPEED);
					camera.plane.y = oldPlaneX * sin(-ROTATE_SPEED) + camera.plane.y * cos(-ROTATE_SPEED);
					break ;
				case (SDLK_LEFT):
					oldDirX = camera.direction.x;
					camera.direction.x = camera.direction.x * cos(ROTATE_SPEED) - camera.direction.y * sin(ROTATE_SPEED);
					camera.direction.y = oldDirX * sin(ROTATE_SPEED) + camera.direction.y * cos(ROTATE_SPEED);
					oldPlaneX = camera.plane.x;
					camera.plane.x = camera.plane.x * cos(ROTATE_SPEED) - camera.plane.y * sin(ROTATE_SPEED);
					camera.plane.y = oldPlaneX * sin(ROTATE_SPEED) + camera.plane.y * cos(ROTATE_SPEED);
					break ;
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

int						main(void)
{
	t_sdl				sdl;

	if (SDL_Init(SDL_INIT_VIDEO) != -1)
	{
		SDL_CreateWindowAndRenderer(
				WIN_SIZE_X, WIN_SIZE_Y, 0, &sdl.window, &sdl.renderer);
		if (sdl.window)
		{
			SDL_SetWindowTitle(sdl.window, WIN_TITLE);
			if ((sdl.event = (SDL_Event *)malloc(sizeof(SDL_Event))))
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