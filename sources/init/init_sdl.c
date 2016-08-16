//
//           :::      ::::::::
//         :+:      :+:    :+:     init_sdl.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 11:50 by alegent
//

#include "wolf3d.h"

t_bool					init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != ERROR)
	{
		SDL_CreateWindowAndRenderer(
				WIN_SIZE_X, WIN_SIZE_Y, 0, &(sdl->window), &(sdl->renderer));
		if (sdl->window)
		{
			SDL_SetWindowTitle(sdl->window, WIN_TITLE);
			if ((IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG) == IMG_INIT_PNG)
			{
				if ((sdl->event = (SDL_Event *)malloc(sizeof(SDL_Event))))
					return (TRUE);
				IMG_Quit();
			}
			SDL_DestroyRenderer(sdl->renderer);
			SDL_DestroyWindow(sdl->window);
		}
		SDL_Quit();
	}
	return (FALSE);
}