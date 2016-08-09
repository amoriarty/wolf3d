//
//           :::      ::::::::
//         :+:      :+:    :+:     init_camera.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 09/08/2016 12:57 by alegent
//

#include "wolf3d.h"

void				init_cam(t_cam *camera)
{
	//TODO CONFIGURATION DEFINES FOR START POSITION AND DIRECTION
	camera->position.x = 22;
	camera->position.y = 12;
	camera->direction.x = -1;
	camera->direction.y = 0;
	camera->plane.x = 0;
	camera->plane.y = 0.66;
}