/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:29 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:19:30 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
