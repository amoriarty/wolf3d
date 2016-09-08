/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:58 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:48:39 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** THE CAMERA MOVE BACKWARD WILL IT HIT NOTHING
** MOVE_SPEED CONFIGURABLE IN WOLF3D.H
*/

void					move_down(t_cam *cam)
{
	if (!map_value((int)(cam->pos.x - cam->dir.x * MOVE_SPEED),
				(int)cam->pos.y))
		cam->pos.x -= cam->dir.x * MOVE_SPEED;
	if (!map_value((int)cam->pos.x,
				(int)(cam->pos.y - cam->dir.y * MOVE_SPEED)))
		cam->pos.y -= cam->dir.y * MOVE_SPEED;
}
