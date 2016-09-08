/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:20:17 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:51:51 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** WILL CHANGE THE CAMERA DIRECTION TO THE LEFT.
** ROTATE SPEED CONFIGURABLE IN WOLF3D.H
*/

void					rotate_left(t_cam *cam)
{
	double				old_dir_x;
	double				old_plane_x;

	old_dir_x = cam->dir.x;
	old_plane_x = cam->plane.x;
	cam->dir.x =
			cam->dir.x * cos(ROTATE_SPEED) - cam->dir.y * sin(ROTATE_SPEED);
	cam->dir.y =
			old_dir_x * sin(ROTATE_SPEED) + cam->dir.y * cos(ROTATE_SPEED);
	cam->plane.x =
			cam->plane.x * cos(ROTATE_SPEED) - cam->plane.y * sin(ROTATE_SPEED);
	cam->plane.y =
			old_plane_x * sin(ROTATE_SPEED) + cam->plane.y * cos(ROTATE_SPEED);
}
