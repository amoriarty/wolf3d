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
static int 		game_loop(t_sdl *sdl)
{
	t_cam 		cam;

	init_cam(&cam);
	while (TRUE) // SO WHILE TRUE ...
	{
		draw_background(sdl);
		SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 0, 0);
		raycasting(sdl, &cam);
		SDL_RenderPresent(sdl->renderer);
		SDL_WaitEvent(sdl->event);
		if (sdl->event->type == SDL_QUIT)
			return (SUCCESS);
		//TODO KEY REPEAT
		//TODO ESCAPE KEY TO QUIT

		// THE TROUBLE BEGIN HERE
		if (sdl->event->type == SDL_KEYDOWN)
		{

			double oldDirX, oldPlaneX;
			switch (sdl->event->key.keysym.sym)
			{
				case (SDLK_UP):
					if (!map_value((int) (cam.pos.x +
										  cam.dir.x * MOVE_SPEED),
								   (int) cam.pos.y))
						cam.pos.x += cam.dir.x * MOVE_SPEED;
					if (!map_value((int) cam.pos.x,
								   (int) (cam.pos.y +
										  cam.dir.y * MOVE_SPEED)))
						cam.pos.y += cam.dir.y * MOVE_SPEED;
					break;
				case (SDLK_DOWN):
					if (!map_value((int) (cam.pos.x -
										  cam.dir.x * MOVE_SPEED),
								   (int) cam.pos.y))
						cam.pos.x -= cam.dir.x * MOVE_SPEED;
					if (!map_value((int) cam.pos.x,
								   (int) (cam.pos.y -
										  cam.dir.y * MOVE_SPEED)))
						cam.pos.y -= cam.dir.y * MOVE_SPEED;
					break;
				case (SDLK_RIGHT):
					oldDirX = cam.dir.x;
					cam.dir.x =
							cam.dir.x * cos(-ROTATE_SPEED) -
							cam.dir.y * sin(-ROTATE_SPEED);
					cam.dir.y = oldDirX * sin(-ROTATE_SPEED) +
										 cam.dir.y *
										 cos(-ROTATE_SPEED);
					oldPlaneX = cam.plane.x;
					cam.plane.x = cam.plane.x * cos(-ROTATE_SPEED) -
									 cam.plane.y * sin(-ROTATE_SPEED);
					cam.plane.y = oldPlaneX * sin(-ROTATE_SPEED) +
									 cam.plane.y * cos(-ROTATE_SPEED);
					break;
				case (SDLK_LEFT):
					oldDirX = cam.dir.x;
					cam.dir.x =
							cam.dir.x * cos(ROTATE_SPEED) -
							cam.dir.y * sin(ROTATE_SPEED);
					cam.dir.y = oldDirX * sin(ROTATE_SPEED) +
										 cam.dir.y * cos(ROTATE_SPEED);
					oldPlaneX = cam.plane.x;
					cam.plane.x = cam.plane.x * cos(ROTATE_SPEED) -
									 cam.plane.y * sin(ROTATE_SPEED);
					cam.plane.y = oldPlaneX * sin(ROTATE_SPEED) +
									 cam.plane.y * cos(ROTATE_SPEED);
					break;
			}
		}
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

	if (SDL_Init(SDL_INIT_VIDEO) != ERROR)
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