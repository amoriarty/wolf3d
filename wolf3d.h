//
//           :::      ::::::::
//         :+:      :+:    :+:     wolf3d.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 04/08/2016 15:17 by alegent
//

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "sdl.h"

# define WIN_SIZE_X (800)
# define WIN_SIZE_Y (600)

typedef struct s_sdl		t_sdl;
struct 						s_sdl
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	SDL_Event				*event;
};

#endif
