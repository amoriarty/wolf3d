/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:15:47 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:31:43 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					main(void)
{
	t_all			all;

	if (init_sdl(&(all.sdl)))
	{
		if (init_game(&(all.game)))
			game_loop(&all);
		destroy_sdl(&(all.sdl));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
