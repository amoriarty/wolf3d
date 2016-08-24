//
//           :::      ::::::::
//         :+:      :+:    :+:     defines.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 11:46 by alegent
//

#ifndef DEFINES_H
# define DEFINES_H

// SDL CONFIGURATION
# define SDL_FLAG (SDL_INIT_VIDEO)
# define WIN_FLAG (0)
# define IMG_FLAG (IMG_INIT_PNG)

// WINDOW CONFIGURATIONS
# define WIN_WIDHT (800)
# define WIN_HEIGHT (600)
# define WIN_TITLE ("Wolf3D")

// PATH CONFIGURATION
# define MAP_PATH ("misc/map")
# define TEXTURE_PATH ("misc/texture")
# define WALL_TEXTURE_PATH ("misc/texture/wall.bmp")
# define FLOOR_TEXTURE_PATH ("misc/texture/floor.bmp")
# define SKY_TEXTURE_PATH ("misc/texture/sky.bmp")

// PLAYER CONFIGURATION
# define PLAYER_START_X (39)
# define PLAYER_START_Y (19)

// CAMERA CONFIGURATION
# define MOVE_SPEED (0.5)
# define ROTATE_SPEED (0.1)

#endif
