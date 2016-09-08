/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:17:35 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:42:12 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				check_move(t_all *all)
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
