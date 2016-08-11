//
//           :::      ::::::::
//         :+:      :+:    :+:     convert_file.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 11/08/2016 13:17 by alegent
//

#include "wolf3d.h"
#include "level.h"

int 					**convert_file(t_tmp *tmp, int lnb)
{
	int 				y;
	int 				x;
	int 				**tab;

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