//
// Created by Alexandre LEGENT on 9/8/16.
//

#ifndef FLOOR_H
# define FLOOR_H

typedef struct s_floor			t_floor;
struct 							s_floor
{
	t_coor						floor;
	double 						dist_wall;
	double 						dist_player;
	double 						current_dist;
	double 						weight;
	t_coor						current_floor;
	t_coor						texture;
};

#endif
