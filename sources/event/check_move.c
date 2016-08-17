//
//           :::      ::::::::
//         :+:      :+:    :+:     check_move.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 17/08/2016 16:14 by alegent
//

#include "wolf3d.h"

void 			check_move(t_all *all)
{
	if (all->game.arrow[UP])
		move_up(&(all->game.cam));
	if (all->game.arrow[DOWN])
		move_down(&(all->game.cam));
	if (all->game.arrow[LEFT])
		rotate_left(&(all->game.cam));
	if (all->game.arrow[RIGHT])
		rotate_right(&(all->game.cam));
	raycasting(all);
}