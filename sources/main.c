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
#include "sdl.h"

int						main(void)
{
	t_bool				on;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			events;

	on = TRUE;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		dprintf(STDERR_FILENO, "SDL_Init error: %s\n", SDL_GetError());
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
	if (!window)
	{
		dprintf(STDERR_FILENO, "SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	SDL_SetWindowTitle(window, "SDL TEST");
	//DRAW RECTANGLE
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	for (int x = 0; x < 800; x++)
		for (int y = 0; y < 600; y++)
			SDL_RenderDrawPoint(renderer, x, y);
	SDL_RenderPresent(renderer);
	while (on)
	{
		SDL_WaitEvent(&events);
		if (events.type == SDL_QUIT)
			on = FALSE;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}