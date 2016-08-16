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

typedef struct s_all		t_all;
typedef struct s_map		t_map;
typedef struct s_sdl		t_sdl;
typedef struct s_coor		t_coor;
typedef struct s_cam		t_cam;
typedef struct s_ray		t_ray;
typedef struct s_dda		t_dda;



struct 						s_map
{
	int 					width;
	int 					height;
	int 					**map;
};

struct 						s_sdl
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	SDL_Event				*event;
	SDL_Surface				*wall;
	SDL_Surface				*floor;
	SDL_Surface				*sky;
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

struct 						s_all
{
	t_sdl					sdl;
};

#endif
