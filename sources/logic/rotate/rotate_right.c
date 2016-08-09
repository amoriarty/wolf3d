//
//           :::      ::::::::
//         :+:      :+:    :+:     rotate_right.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 17:00 by alegent
//

#include "wolf3d.h"

/*
** WILL CHANGE THE CAMERA DIRECTION TO THE RIGHT.
** ROTATE SPEED CONFIGURABLE IN WOLF3D.H
*/

void 					rotate_right(t_cam *cam)
{
	double 				old_dir_x;
	double 				old_plane_x;

	old_dir_x = cam->dir.x;
	old_plane_x = cam->plane.x;
	cam->dir.x =
			cam->dir.x * cos(-ROTATE_SPEED) - cam->dir.y * sin(-ROTATE_SPEED);
	cam->dir.y =
			old_dir_x * sin(-ROTATE_SPEED) + cam->dir.y * cos(-ROTATE_SPEED);
	cam->plane.x =
			cam->plane.x * cos(-ROTATE_SPEED) - cam->plane.y * sin(-ROTATE_SPEED);
	cam->plane.y =
			old_plane_x * sin(-ROTATE_SPEED) + cam->plane.y * cos(-ROTATE_SPEED);
}