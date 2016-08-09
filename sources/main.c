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
				game_loop(&sdl);
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