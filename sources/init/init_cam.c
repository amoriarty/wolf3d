//
//           :::      ::::::::
//         :+:      :+:    :+:     init_cam.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 12:57 by alegent
//

#include "wolf3d.h"

/*
** INIT THE INITIAL CONFIGURATION OF THE PLAYER CAMERA
*/

t_bool				init_cam(t_cam *camera)
{
	//TODO CONFIGURATION DEFINES FOR START pos AND DIRECTION
	camera->pos.x = 22;
	camera->pos.y = 12;
	camera->dir.x = -1;
	camera->dir.y = 0;
	camera->plane.x = 0;
	camera->plane.y = 0.66;
	return (SUCCESS);
}