//
//           :::      ::::::::
//         :+:      :+:    :+:     struct.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 16/08/2016 11:47 by alegent
//

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map		t_map;
typedef struct s_coor		t_coor;
typedef struct s_cam		t_cam;
typedef struct s_ray		t_ray;
typedef struct s_dda		t_dda;
typedef struct s_game		t_game;
typedef struct s_win		t_win;
typedef struct s_sdl		t_sdl;
typedef struct s_all		t_all;



struct 						s_map
{
	int 					width;
	int 					height;
	int 					**map;
};

struct 						s_coor
{
	double 					x;
	double 					y;
};

struct 						s_cam
{
	t_coor					pos;
	t_coor					dir;
	t_coor					plane;
};

struct 						s_ray
{
	t_coor					pos;
	t_coor					dir;
};

struct 						s_dda
{
	t_coor					map;
	t_coor					side;
	t_coor					delta;
	t_coor					step;
	int 					s;
};

struct 						s_game
{
	t_bool					loop;
	t_cam					cam;
};

struct 						s_win
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	int 					width;
	int 					height;
};

struct 						s_sdl
{
	t_win					win;
	SDL_Event				*event;
	SDL_Surface				*wall;
};

struct 						s_all
{
	t_sdl					sdl;
	t_game					game;
};

#endif
