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

//TODO MAKE IT PLAYABLE
	//TODO GRAPHIC
		//TODO DRAW FLOOR AND SKY
		//TODO RAYCAST ONLY ON EVENTS.
	//TODO SOUNDS
	//TODO KEY REPEAT
	//TODO PLAYER FIRST POSITION IN MAP FILE
	//TODO A LOT OF MAP FILE
	//TODO WOLF3D STATE MENU
	//TODO TRIGGERING
		//TODO DOORS
		//TODO ENNEMY
	//TODO PLAYER
		//TODO LIFE
		//TODO AMMO
//TODO MAKE IT CLEAR !

/*
** SETTING SDL STRUCTURE
** (OPEN WINDOW, SETTING TITLE, SETTING RENDERER,
** ALLOCATE SDL_EVENTS AND FINALLY GIVE THE STRUCTURE TO GAME FUNCTION)
*/

int 				main(void)
{
	t_all			all;

	if (init_sdl(&(all.sdl)))
	{
		game_loop(&(all.sdl));
		destroy_sdl(&(all.sdl));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}