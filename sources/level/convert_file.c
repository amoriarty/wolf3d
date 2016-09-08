/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:16 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:47:00 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "level.h"

int						**convert_file(t_tmp *tmp, int lnb)
{
	int					y;
	int					x;
	int					**tab;

	y = -1;
	if ((tab = (int **)malloc(sizeof(int *) * lnb)))
	{
		while (++y < lnb)
		{
			x = -1;
			if ((tab[y] = (int *)malloc(sizeof(int) * tmp->size)))
			{
				while (++x < tmp->size)
					tab[y][x] = tmp->line[x] - '0';
			}
			tmp = tmp->next;
		}
		return (tab);
	}
	return (NULL);
}
