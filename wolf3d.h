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
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <fcntl.h>

/*
** DEFINES
*/

# define WIN_SIZE_X (800)
# define WIN_SIZE_Y (600)
# define WIN_TITLE ("Wolf3D")

# define MAP_PATH ("misc/map")

# define GREYSTONE_TEXTURE ("misc/texture/greystone.png")

# define BACKGROUND_COLOR 0, 0, 0, 0

# define MOVE_SPEED (0.5)
# define ROTATE_SPEED (0.1)

/*
** DATA STRUCT
*/

typedef struct s_map		t_map;
struct 						s_map
{
	int 					width;
	int 					height;
	int 					**map;
};

typedef struct s_sdl		t_sdl;
struct 						s_sdl
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	SDL_Event				*event;
	SDL_Surface				*wall;
};

typedef struct s_coor		t_coor;
struct 						s_coor
{
	double 					x;
	double 					y;
};

typedef struct s_cam		t_cam;
struct 						s_cam
{
	t_coor					pos;
	t_coor					dir;
	t_coor					plane;
};

typedef struct s_ray		t_ray;
struct 						s_ray
{
	t_coor					pos;
	t_coor					dir;
};

typedef struct s_dda		t_dda;
struct 						s_dda
{
	t_coor					map;
	t_coor					side;
	t_coor					delta;
	t_coor					step;
	int 					s;
};

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
