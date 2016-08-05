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

void 					draw_full_window(SDL_Renderer *renderer, int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int x = 0; x < WIN_SIZE_X; x++)
		for (int y = 0; y < WIN_SIZE_Y; y++)
			SDL_RenderDrawPoint(renderer, x, y);
	SDL_RenderPresent(renderer);
}

int						main(void)
{
	t_bool				on;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			events;

	on = TRUE;

	//SDL INITIALISATION
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		dprintf(STDERR_FILENO, "SDL_Init error: %s\n", SDL_GetError());
		SDL_Quit();
		return (EXIT_FAILURE);
	}

	//SDL WINDOW CREATION
	SDL_CreateWindowAndRenderer(WIN_SIZE_X, WIN_SIZE_Y, 0, &window, &renderer);
	if (!window)
	{
		dprintf(STDERR_FILENO, "SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	SDL_SetWindowTitle(window, "SDL TEST");

	//DRAW FULL WINDOW
	draw_full_window(renderer, 0, 0, 255, 0);

	//SDL LOOP
	while (on)
	{
		SDL_WaitEvent(&events);
		if (events.type == SDL_QUIT)
			on = FALSE;
		if (events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_g)
			draw_full_window(renderer, 0, 255, 0, 0);
	}

	//SDL DESTROY EVERYTHING
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}