/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:12:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/30 20:34:00 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_stat	find_node(int fd, t_util **phead, t_util **pcurr)
{
	if (*phead == NULL)
	{
		*pcurr = malloc(sizeof(t_util));
		if (!(*pcurr))
			return (FAIL);
		(*pcurr)->fd = fd;
		(*pcurr)->index = -1;
		(*pcurr)->next = NULL;
		*phead = *pcurr;
		return (SUCCESS);
	}
	while ((*phead)->fd != fd)
		phead = &((*phead)->next);
	*pcurr = *phead;
	return (SUCCESS);
}

t_stat	init_string(t_string *ps)
{
	ps->str = malloc(BUFFER_SIZE);
	if (!ps->str)
		return (FAIL);
	ps->len = 0;
	ps->malloc_size = BUFFER_SIZE;
	return (SUCCESS);
}

char	*delete_current_node(int fd, t_util *head)
{
	t_util	*temp;

	if (!head->next)
	{
		temp = head->next;
		free(head);
		head = temp;
		return (NULL);
	}
	while (head->next && head->next->fd != fd)
		head = head->next;
	temp = head->next;
	head->next = head->next->next;
	free(temp);
	temp = NULL;
	return (NULL);
}

char	*free_string(t_string *ps)
{
	free(ps->str);
	ps->str = NULL;
	return (NULL);
}