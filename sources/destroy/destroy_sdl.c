//
//           :::      ::::::::
//         :+:      :+:    :+:     destroy_sdl.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 11:58 by alegent
//

#include "wolf3d.h"

void					destroy_sdl(t_sdl *sdl)
{
	IMG_Quit();
	SDL_DestroyRenderer(sdl->win.renderer);
	SDL_DestroyWindow(sdl->win.window);
	SDL_Quit();
}