/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:12:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/28 22:04:39 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	find_node(int fd, t_util *head, t_util **pcurr)
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

t_status	init_string(t_string *ps)
{
	ps->str = malloc(BUFFER_SIZE);
	if (!ps->str)
		return (FAIL);
	ps->len = 0;
	ps->malloc_size = BUFFER_SIZE;
	return (SUCCESS);
}

char	*delete_current_node(t_util **pn) //////////현재 노드 지우고 다음 노드로 연결해주는 과정 필요
{
	free(*pn);
	*pn = NULL;
	return (NULL);
}