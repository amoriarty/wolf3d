//
//           :::      ::::::::
//         :+:      :+:    :+:     move_down.cpp
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 16:54 by alegent
//

#include "wolf3d.h"

/*
** THE CAMERA MOVE BACKWARD WILL IT HIT NOTHING
** MOVE_SPEED CONFIGURABLE IN WOLF3D.H
*/

void 					move_down(t_cam *cam)
{
	if (!map_value((int) (cam->pos.x - cam->dir.x * MOVE_SPEED),
				   (int) cam->pos.y))
		cam->pos.x -= cam->dir.x * MOVE_SPEED;
	if (!map_value((int) cam->pos.x,
				   (int) (cam->pos.y - cam->dir.y * MOVE_SPEED)))
		cam->pos.y -= cam->dir.y * MOVE_SPEED;
}