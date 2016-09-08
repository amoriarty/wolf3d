/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:15:24 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:29:40 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_aw			t_aw;
typedef struct s_map		t_map;
typedef struct s_coor		t_coor;
typedef struct s_cam		t_cam;
typedef struct s_ray		t_ray;
typedef struct s_dda		t_dda;
typedef struct s_game		t_game;
typedef struct s_win		t_win;
typedef struct s_sdl		t_sdl;
typedef struct s_all		t_all;

enum						e_aw
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct						s_map
{
	int						width;
	int						height;
	int						**map;
};

struct						s_coor
{
	double					x;
	double					y;
};

struct						s_cam
{
	t_coor					pos;
	t_coor					dir;
	t_coor					plane;
};

struct						s_ray
{
	t_coor					pos;
	t_coor					dir;
};

struct						s_dda
{
	t_coor					map;
	t_coor					side;
	t_coor					delta;
	t_coor					step;
	int						s;
	int						line_height;
	double					pwd;
	double					wall_x;
	int						start;
	int						end;
};

struct						s_game
{
	t_bool					loop;
	t_cam					cam;
	t_ray					ray;
	t_dda					dda;
	t_coor					iter;
	int						arrow[4];
};

struct						s_win
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	int						width;
	int						height;
};

struct						s_sdl
{
	t_win					win;
	SDL_Event				*event;
	SDL_Surface				*wall;
	SDL_Surface				*floor;
	SDL_Surface				*sky;
};

struct						s_all
{
	t_sdl					sdl;
	t_game					game;
};

#endif
