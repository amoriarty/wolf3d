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

static void				draw_background(t_sdl *sdl)
{
	int 				x;
	int 				y;

	x = -1;
	while (++x < WIN_SIZE_X)
	{
		y = -1;
		while (++y < WIN_SIZE_Y)
			SDL_RenderDrawPoint(sdl->renderer, x, y);
	}
}

//TEMPORARY LOOP
static int 				game_loop(t_sdl *sdl)
{
	// ON IS THE BOOLEAN THAT DEFINE LOOPS
	t_bool				on;

	// SET ON AT TRUE
	on = TRUE; // KEEP THAT

	// THE TROUBLE BEGIN HERE
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	//double time = 0;
	//double oldTime = 0;
	// THE TROUBLE FINISH HERE

	while (on) // SO WHILE TRUE ...
	{
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0); // (SET GREEN COLOR)
		draw_background(sdl);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 0, 0); // (SET GREEN COLOR)
		// THE TROUBLE CONTINUE HERE
		for (int x = 0; x < WIN_SIZE_X; x++)
		{
			double cameraX = 2 * x / (double)WIN_SIZE_X - 1;
			double rayPosX = posX, rayPosY = posY;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
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

			SDL_RenderDrawLine(sdl->renderer, x, drawStart, x, drawEnd);
		}

		//timing for input and FPS counter
		//oldTime = time;
		//time = clock();
		//double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds

		//speed modifiers
		double moveSpeed = 0.5; //frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = 0.2; //frameTime * 3.0; //the constant value is in radians/second
		//THE TROUBLE FINISH HERE

		// SDL EVENT WAITING HERE
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
			on = FALSE;

		// THE TROUBLE BEGIN HERE
		if (sdl->event->type == SDL_KEYDOWN)
		{
			double oldDirX, oldPlaneX;
			switch (sdl->event->key.keysym.sym)
			{
				case (SDLK_UP):
					if (!map_value((int)(posX + dirX * moveSpeed), (int)posY))
						posX += dirX * moveSpeed;
					if (!map_value((int)posX, (int)(posY + dirY * moveSpeed)))
						posY += dirY * moveSpeed;
					break ;
				case (SDLK_DOWN):
					if (!map_value((int)(posX - dirX * moveSpeed), (int)posY))
						posX -= dirX * moveSpeed;
					if (!map_value((int)posX, (int)(posY - dirY * moveSpeed)))
						posY -= dirY * moveSpeed;
					break ;
				case (SDLK_RIGHT):
					oldDirX = dirX;
					dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
					dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
					oldPlaneX = planeX;
					planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
					planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
					break ;
				case (SDLK_LEFT):
					oldDirX = dirX;
					dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
					dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
					oldPlaneX = planeX;
					planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
					planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
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