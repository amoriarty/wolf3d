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
	if (SDL_Init(SDL_FLAG) != ERROR)
	{
		if (init_window(&(sdl->win)))
		{
			//SDL_SetRelativeMouseMode(SDL_TRUE);
			//SDL_SetWindowGrab(sdl->win.window, SDL_TRUE);
			//if ((IMG_Init(IMG_FLAG)&IMG_FLAG) == IMG_FLAG)
			//{
				if ((sdl->event = (SDL_Event *)malloc(sizeof(SDL_Event))))
					return (TRUE);
			//	IMG_Quit();
		//	}
			SDL_DestroyRenderer(sdl->win.renderer);
			SDL_DestroyWindow(sdl->win.window);
		}
		SDL_Quit();
	}
	return (FALSE);
}
