/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:15:17 by alegent           #+#    #+#             */
/*   Updated: 2016/09/08 13:27:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

/*
** TEMPORARY PARSING STRUCT
*/

typedef struct s_tmp			t_tmp;
struct							s_tmp
{
	char						*line;
	int							size;
	t_tmp						*next;
};

/*
** PROTOTYPES
*/

t_tmp							*read_file(int *lnb);
int								**convert_file(t_tmp *tmp, int lnb);

#endif
