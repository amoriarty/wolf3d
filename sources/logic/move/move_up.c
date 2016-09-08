/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:20:05 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:49:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** THE CAMERA MOVE TOWARD WILL IT HIT NOTHING
** MOVE_SPEED CONFIGURABLE IN WOLF3D.H
*/

void						move_up(t_cam *cam)
{
	if (!map_value((int)(cam->pos.x + cam->dir.x * MOVE_SPEED),
				(int)cam->pos.y))
		cam->pos.x += cam->dir.x * MOVE_SPEED;
	if (!map_value((int)cam->pos.x,
				(int)(cam->pos.y + cam->dir.y * MOVE_SPEED)))
		cam->pos.y += cam->dir.y * MOVE_SPEED;
}
