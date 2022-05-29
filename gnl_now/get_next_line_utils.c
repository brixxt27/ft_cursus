/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:12:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/29 20:51:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_stat	find_node(int fd, t_util *head, t_util **pcurr)
{
	if (head == NULL)
	{
		*pcurr = malloc(sizeof(t_util));
		if (!(*pcurr))
			return (FAIL);
		(*pcurr)->fd = fd;
		(*pcurr)->index = -1;
		(*pcurr)->next = NULL;
		return (SUCCESS);
	}
	while (head->fd != fd)
		head = head->next;
	*pcurr = head;
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
	char	*temp;

	while (!(head->next) && head->next->fd != fd)
		head = head->next;
	temp = head->next;
	head->next = head->next->next;
	free(temp);
	temp = NULL;
	return (NULL);
}

char	*delete_all_node(t_util *head)
{
	t_util	*temp;

	while (!head)
	{
		temp = head->next;
		free(head);
		head = NULL;
		head = temp;
	}
	return (NULL);
}