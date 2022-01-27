/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:03:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/27 18:23:14 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

typedef struct s_gnl
{
	static char	*save;
	char		*ret;
}	t_gnl;

char	*read_and_save(char *ret);
char	*cut_before_new_line(t_gnl *pset);

char	*get_next_line(int fd)
{
	t_gnl	set;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	set.ret = read_and_save(set.ret);
	if ()
		set.ret = cut_before_new_line(&set);
	return (set.ret);
}
