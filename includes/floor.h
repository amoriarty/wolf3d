/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:45:03 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 15:46:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_H
# define FLOOR_H

typedef struct s_floor			t_floor;
struct							s_floor
{
	t_coor						floor;
	double						dist_wall;
	double						dist_player;
	double						current_dist;
	double						weight;
	t_coor						current_floor;
	t_coor						texture;
};

#endif
