/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:12:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/28 17:14:37 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	find_node(t_util **pn, int fd)
{
	t_util	*curr;

	if (*pn == NULL)
	{
		curr = malloc(sizeof(t_util));
		if (!curr)
			return (FAIL);
		curr->index = -1;
		curr->fd = fd;
		*pn = curr;
		return (SUCCESS);
	}
	while ((*pn)->fd != fd)
	{
		*pn = (*pn)->next; 
	}
	return (SUCCESS);
}

t_status	init_string(t_string *ps)
{
	ps->str = malloc(BUFFER_SIZE);
	if (!ps->str)
		return (FAIL);
	ps->len = 0;
	ps->malloc_size = BUFFER_SIZE;
	return (SUCCESS);
}

char		*delete_current_node(t_util **pn)
{
	free(*pn);
	*pn = NULL;
	return (NULL);
}