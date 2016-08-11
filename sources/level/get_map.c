//
//           :::      ::::::::
//         :+:      :+:    :+:     get_map.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 11/08/2016 12:51 by alegent
//

#include "wolf3d.h"
#include "level.h"

static void 			free_tmp(t_tmp *head)
{
	if (head->next)
		free_tmp(head->next);
	free(head->line);
	free(head);
}

t_map 					*get_map(void)
{
	t_map				*map;
	t_tmp				*list;

	if ((map = (t_map *)malloc(sizeof(t_map))))
	{
		list = read_file(&(map->height));
		map->width = list->size;
		map->map = convert_file(list, map->height);
		free_tmp(list);
		return (map);
	}
	return (NULL);
}