//
//           :::      ::::::::
//         :+:      :+:    :+:     read_file.c
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 11/08/2016 13:14 by alegent
//

#include "wolf3d.h"
#include "level.h"

static t_tmp 			*push_new(t_tmp *first, char *line)
{
	t_tmp				*new;
	t_tmp				*tmp;

	if ((new = (t_tmp *)malloc(sizeof(t_tmp))))
	{
		new->line = line;
		new->size = (int)ft_strlen(line);
		new->next = NULL;
		if (first)
		{
			tmp = first;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			return (first);
		}
		return (new);
	}
	return (NULL);
}

t_tmp					*read_file(int *lnb)
{
	int 				fd;
	char 				*line;
	t_tmp				*first;

	*lnb = 0;
	first = NULL;
	if ((fd = open(MAP_PATH, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line))
		{
			first = push_new(first, line);
			(*lnb)++;
		}
		free(line);
		close(fd);
		return (first);
	}
	return (NULL);
}