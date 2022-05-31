/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/31 19:20:14 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_util	*head;
	t_string		string;
	t_util			*curr;
	t_stat			stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (delete_current_node(fd, head, &head));
	if (find_node(fd, &head, &curr) == FAIL)
		return (delete_current_node(fd, head, &head));
	if (init_string(&string) == FAIL)
		return (delete_current_node(fd, head, &head));
	if (curr->index != -1)
	{
		if (copy_buffer_to_string(curr, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string));
	}
	stat = read_and_copy_to_str(fd, curr, &string);
	if (stat != SUCCESS)
	{
		delete_current_node(fd, head, &head);
		if (stat == FAIL)
			free_string(&string);
		return (NULL);
	}
	return (copy_string_to_ret_and_add_nul(&string));
}

t_stat	read_and_copy_to_str(int fd, t_util *curr, t_string *ps)
{
	t_stat	eol;

	eol = NOT_EXIST;
	while (eol == NOT_EXIST)
	{
		curr->ret_read = read(fd, curr->buf, BUFFER_SIZE);
		if (curr->ret_read < 0)
			return (FAIL);
		if (curr->ret_read == 0)
		{
			if (ps->len == 0)
				return (FAIL);
			return (SUCCESS);
		}
		curr->index = 0;
		eol = copy_buffer_to_string(curr, ps);
		if (eol == MALLOC_ERROR)
			return (MALLOC_ERROR);
	}
	return (SUCCESS);
}

t_stat	copy_buffer_to_string(t_util *curr, t_string *ps)
{
	int	copy_len;
	int	i;

	copy_len = curr->ret_read - curr->index;
	i = 0;
	while (i < copy_len)
	{
		if (ps->len == ps->malloc_size)
		{
			if (stretch_string(ps) == FAIL)
				return (MALLOC_ERROR);
		}
		ps->str[ps->len++] = curr->buf[curr->index++];
		i++;
		if (curr->buf[curr->index - 1] == '\n')
			return (EXIST);
	}
	return (NOT_EXIST);
}

char	*copy_string_to_ret_and_add_nul(t_string *ps)
{
	char			*ret;
	unsigned char	*cp_dst;
	unsigned char	*cp_src;
	size_t			len;

	ret = malloc(ps->len + 1);
	if (!ret)
		return (NULL);
	len = ps->len;
	cp_dst = (unsigned char *)ret;
	cp_src = (unsigned char *)ps->str;
	while (len--)
		*cp_dst++ = *cp_src++;
	free_string(ps);
	ret[ps->len] = '\0';
	return (ret);
}