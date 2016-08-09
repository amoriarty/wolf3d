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
//WINDOW
# define WIN_SIZE_X (800)
# define WIN_SIZE_Y (600)
# define WIN_TITLE ("Wolf3D")

//LEVEL
# define LVL_SIZE 24

//COLOR
# define BACKGROUND_COLOR 0, 0, 0, 0

//CAMERA SETTING
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
	t_coor					position;
	t_coor					direction;
	t_coor					plane;
};

/*
** DRAW PROTOTYPES
*/

void						draw_background(t_sdl *sdl);
//TODO DON'T KEEP IT THAT WAY !
void 						draw_vertical(SDL_Renderer *renderer, int x, int draw_start, int draw_end);

/*
** INIT PROTOTYPES
*/

void						init_cam(t_cam *camera);

/*
** LEVEL PROTOTYPE
*/

int 						map_value(int x, int y);

#endif
