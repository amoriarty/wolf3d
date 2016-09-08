/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:15:30 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:30:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL2/SDL.h>
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

void						draw_wall(t_all *all);
void						draw_floor(t_all *all);

/*
** EVENT PROTOTYPES
*/

void						wait_event(t_all *all);
void						key_hook(t_all *all, SDL_Keycode sym);

/*
** INIT PROTOTYPES
*/

t_bool						init_sdl(t_sdl *sdl);
t_bool						init_window(t_win *win);
t_bool						init_game(t_game *game);
t_bool						init_cam(t_cam *camera);
void						init_ray(t_all *all);
void						init_dda(t_dda *dda_n, t_ray *ray);

/*
** LEVEL PROTOTYPES
*/

int							map_value(int x, int y);
t_map						*get_map(void);

/*
** LOGIC PROTOTYPES
*/

int							game_loop(t_all *all);
int							dda(t_dda *dda);
void						raycasting(t_all *all);

/*
** LOGIC/MOVE PROTOTYPES
*/

void						move_up(t_cam *cam);
void						move_down(t_cam *cam);

/*
** LOGIC/ROTATE PROTOTYPES
*/

void						rotate_left(t_cam *cam);
void						rotate_right(t_cam *cam);

/*
** TOOLS PROTOTYPES
*/

Uint32						get_pixel(SDL_Surface *surface, int x, int y);

#endif
