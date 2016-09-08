/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:21:57 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:22:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SDL_FLAG (SDL_INIT_VIDEO)
# define WIN_FLAG (0)
# define IMG_FLAG (IMG_INIT_PNG)

# define WIN_WIDHT (800)
# define WIN_HEIGHT (600)
# define WIN_TITLE ("Wolf3D")

# define MAP_PATH ("misc/map")
# define TEXTURE_PATH ("misc/texture")
# define WALL_TEXTURE_PATH ("misc/texture/wall.bmp")
# define FLOOR_TEXTURE_PATH ("misc/texture/floor.bmp")
# define SKY_TEXTURE_PATH ("misc/texture/sky.bmp")

# define PLAYER_START_X (39)
# define PLAYER_START_Y (19)

# define MOVE_SPEED (0.5)
# define ROTATE_SPEED (0.1)

#endif
