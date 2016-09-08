/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:43:29 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:43:32 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** INIT THE INITIAL CONFIGURATION OF THE PLAYER CAMERA
*/

t_bool				init_cam(t_cam *camera)
{
	camera->pos.x = PLAYER_START_X;
	camera->pos.y = PLAYER_START_Y;
	camera->dir.x = -1;
	camera->dir.y = 0;
	camera->plane.x = 0;
	camera->plane.y = 0.66;
	return (SUCCESS);
}
