/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/28 17:30:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_util	*node;
	t_string		string;
	char			*ret;
	
	if (fd < 0 || BUFFER_SIZE <=0)
		return (NULL);
	if (find_node(&node, fd) == FAIL)
		return (NULL);
	if (init_string(&string) == FAIL)
		return (delete_current_node(&node));
	if (node->index != -1)
	{
		if (copy_static_to_string(node, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string, ret));
	}
	read_and_copy_static_to_string(node, &string);
	return (copy_string_to_ret_and_add_nul(&string, ret));
}

t_eol		copy_static_to_string(t_util *curr, t_string *ps)
{
	if (memcpy_and_check_eol(ps->str, curr->buf, ) == EXIST) //뭐하죠
		return (EXIST);
	return (NOT_EXIST);
}

t_eol		memcpy_and_check_eol(char *dest, const char *src, size_t len);
{
	while (curr->index < BUFFER_SIZE)
	{
		(ps->*str)++ = curr->buf[curr->index++];
		if (curr->buf[curr->index] != '\n')
			return (EXIST);
	}
	return (NOT_EXIST);
}
char		*copy_string_to_ret_and_add_nul(t_string *ps, char *ret);
void		read_and_copy_static_to_string(t_util *node, t_string *ps);
char		*delete_all_node(t_util **pn);