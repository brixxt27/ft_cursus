/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/28 22:05:06 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_util	*head;
	t_string		string;
	t_util			*curr;
	
	if (fd < 0 || BUFFER_SIZE <=0)
		return (NULL);
	if (find_node(fd, head, &curr) == FAIL)
		return (NULL);
	if (init_string(&string) == FAIL)
		return (delete_current_node(&head));
	
	/////////// head 를 curr 로 바꿔주기
	if (curr->index != -1)
	{
		if (copy_static_to_string(curr, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string));
	}
	read_and_copy_static_to_string(fd, head, &string); ///////// head 만 넘기고 안쪽에서 curr 을 구해 사용할 예정
	return (copy_string_to_ret_and_add_nul(&string));
}

t_eol	copy_static_to_string(t_util *curr, t_string *ps)
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
	ret[ps->len - 1] = '\0';
	return (ret);
}

void	read_and_copy_static_to_string(int fd, t_util *head, t_string *ps) // head 이용해 curr 찾는 기능 추가
{
	int	ret_read;

	ret_read = read(fd, curr->buf, BUFFER_SIZE);
	if (ret_read < 0)
	{
		delete_all_node()
	}
}
char		*delete_all_node(t_util **pn);