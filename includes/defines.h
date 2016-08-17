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

//TODO DELETE THIS DEFINE
# define WIN_SIZE_X (800)
# define WIN_SIZE_Y (600)
# define GREYSTONE_TEXTURE ("misc/texture/greystone.png")
# define PURPLESTONE_TEXTURE ("misc/texture/purplestone.png")
# define BLUESTONE_TEXTURE ("misc/texture/bluestone.png")
# define BACKGROUND_COLOR 0, 0, 0, 0

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

// PLAYER CONFIGURATION
// CAMERA CONFIGURATION
# define MOVE_SPEED (0.5)
# define ROTATE_SPEED (0.1)

#endif
