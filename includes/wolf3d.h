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
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <fcntl.h>
# include "libft.h"
# include "defines.h"
# include "struct.h"

/*
** DESTROY PROTOTYPES
*/

void						destroy_sdl(t_sdl *sdl);

/*
** DRAW PROTOTYPES
*/

void						draw_background(t_sdl *sdl);
void 						draw_wall(t_sdl *sdl, int x, t_dda *dda_n, t_ray *ray);
void 						draw_vert(SDL_Renderer *r, int x, int y1, int y2);

/*
** EVENT PROTOTYPES
*/

void 						key_hook(SDL_Keycode sym, t_cam *cam);

/*
** INIT PROTOTYPES
*/

t_bool						init_sdl(t_sdl *sdl);
t_bool						init_window(t_win *win);
void						init_cam(t_cam *camera);
void						init_ray(t_ray *ray, t_cam *cam, int x);
void 						init_dda(t_dda *dda_n, t_ray *ray);

/*
** LEVEL PROTOTYPES
*/

int 						map_value(int x, int y);
t_map 						*get_map(void);

/*
** LOGIC PROTOTYPES
*/

int 						game_loop(t_sdl *sdl);
int 						dda(t_dda *dda);
void 						raycasting(t_sdl *sdl, t_cam *cam);

/*
** LOGIC/MOVE PROTOTYPES
*/

void 						move_up(t_cam *cam);
void 						move_down(t_cam *cam);

/*
** LOGIC/ROTATE PROTOTYPES
*/

void 						rotate_left(t_cam *cam);
void 						rotate_right(t_cam *cam);

/*
** TOOLS PROTOTYPES
*/

Uint32						get_pixel(SDL_Surface *surface, int x, int y);

#endif
