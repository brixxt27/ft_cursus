/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/29 22:07:44 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_util	*head;
	t_string		string;
	t_util			*curr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (find_node(fd, head, &curr) == FAIL)
		return (NULL);
	if (init_string(&string) == FAIL)
		return (delete_current_node(fd, head));
	if (curr->index != -1)
	{
		if (copy_buffer_to_string(curr, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string));
	}
	if (read_and_copy_to_str(fd, head, curr, &string) == FAIL)
		return (free_string(&string));
	return (copy_string_to_ret_and_add_nul(&string));
}

t_eol	copy_buffer_to_string(t_util *curr, t_string *ps)
{
	int	copy_len;
	int	i;

	copy_len = BUFFER_SIZE - curr->index;
	i = 0;
	while (i < copy_len)
	{
		ps->str[i] = curr->buf[curr->index];
		ps->len++;
		if (curr->buf[curr->index] == '\n')
		{
			curr->index++;
			return (EXIST);
		}
		if (ps->len == ps->malloc_size)
		{
			// 여기가 문제야! 
			// NULL malloc 실패했을 때 NULL 반환해줘야 하는데 어떻게 할지 생각해 봐야함
			// norm	은 문제 없음
			// 함수도 딱 10 개
			if (stretch_string(ps) == FAIL)
				return (NULL);
		}
		curr->index++;
		i++;
	}
	return (NOT_EXIST);
}

static void	memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*cp_dst;
	unsigned char	*cp_src;

	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	while (len--)
		*cp_dst++ = *cp_src++;
}

char	*copy_string_to_ret_and_add_nul(t_string *ps)
{
	char	*ret;

	ret = malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	memcpy(ret, ps->str, ps->len);
	free_string(ps);
	ret[ps->len - 1] = '\0';
	return (ret);
}

t_stat	read_and_copy_to_str(int fd, t_util *head, t_util *curr, t_string *ps)
{
	int	ret_read;

	while (개행 나올 때까지 반복)
	{
		ret_read = read(fd, curr->buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (delete_all_node_when_read_error(head));
		if (ret_read == 0)
		{
			if (ps->len == 0)
				return (FAIL);
			return (SUCCESS);
		}
	}
}