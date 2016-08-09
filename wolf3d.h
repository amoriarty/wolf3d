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
# include "sdl.h"
# include <time.h>

/*
** DEFINES
*/

# define WIN_SIZE_X (800)
# define WIN_SIZE_Y (600)
# define WIN_TITLE ("Wolf3D")

# define LVL_SIZE 24

# define BACKGROUND_COLOR 0, 0, 0, 0

# define MOVE_SPEED (0.5)
# define ROTATE_SPEED (0.1)

/*
** DATA STRUCT
*/

typedef enum e_map			t_map;
enum 						e_map
{
	NOTHING = 0,
	WALL = 1
};

typedef struct s_sdl		t_sdl;
struct 						s_sdl
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	SDL_Event				*event;
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
};

/*
** DRAW PROTOTYPES
*/

void						draw_background(t_sdl *sdl);
void 						draw_wall(t_sdl *sdl, int x, double perp_wall_dist);
//TODO DON'T KEEP IT THAT WAY !
void 						draw_vertical(SDL_Renderer *renderer, int x, int draw_start, int draw_end);

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

#endif
