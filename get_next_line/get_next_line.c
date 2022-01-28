/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:03:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/28 17:23:32 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct s_gnl
{
	char		*ret;
	static char	*save;
}	t_gnl;

char	*read_and_save(char *str);
char	*make_two_array_based_on_new_line(t_gnl *pset);
int		check_next_new_line(char *str);

char	*get_next_line(int fd)
{
	t_gnl	set;
	char	arr[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	set.ret = read_and_save(arr);
	if (!set.ret)
		return (NULL);
	if (check_next_new_line(set.ret))
	{
		set.ret = make_two_array_based_on_new_line(&set);
		if (!set.ret)
			return (NULL);
	}
	return (set.ret);
}
