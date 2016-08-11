//
//           :::      ::::::::
//         :+:      :+:    :+:     level.h
//       +:+ +:+         +:+
//     +#+  +:+       +#+          By: Alexandre LEGENT <alegent@student.42.fr>
//   +#+#+#+#+#+   +#+
//        #+#    #+#
//       ###   ###########.fr      Created: 11/08/2016 12:56 by alegent
//

#ifndef LEVEL_H
# define LEVEL_H

/*
** TEMPORARY PARSING STRUCT
*/

typedef struct s_tmp			t_tmp;
struct							s_tmp
{
	char 						*line;
	int 						size;
	t_tmp						*next;
};

/*
** PROTOTYPES
*/

t_tmp							*read_file(int *lnb);
int 							**convert_file(t_tmp *tmp, int lnb);

#endif
