/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:19:47 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:50:41 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** AS "Digital Differential Analysis", Google it.
*/

int				dda(t_dda *dda)
{
	int			hit;
	int			side;

	hit = FALSE;
	side = 0;
	while (!hit)
	{
		if (dda->side.x < dda->side.y)
		{
			dda->side.x += dda->delta.x;
			dda->map.x += dda->step.x;
			side = 0;
		}
		else
		{
			dda->side.y += dda->delta.y;
			dda->map.y += dda->step.y;
			side = 1;
		}
		hit = (map_value((int)dda->map.x, (int)dda->map.y)) ? 1 : 0;
	}
	return (side);
}
