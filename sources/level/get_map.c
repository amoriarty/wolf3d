/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:22 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:46:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "level.h"

static void				free_tmp(t_tmp *head)
{
	if (head->next)
		free_tmp(head->next);
	free(head->line);
	free(head);
}

t_map					*get_map(void)
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
