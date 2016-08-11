//
//           :::      ::::::::
//         :+:      :+:    :+:     level.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 05/08/2016 16:12 by alegent
//

#include "wolf3d.h"

int						map_value(int x, int y)
{
	static t_map		*map;

	if (!map)
		map = get_map();
	if (x >= map->width || y >= map->height)
		return (ERROR);
	return (map->map[y][x]);
}