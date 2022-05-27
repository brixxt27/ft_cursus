/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:34:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/05/27 22:02:02 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_util	*buf;
	t_string		string;
	char			*ret;
	
	if (fd < 0 || BUFFER_SIZE <=0)
		return (NULL);
	buf = find_node(fd);
	init_string(&string); // 함수 안이 아니라 바깥에서 예외처리 가능, list 삭제를 바깥에서 if 로 해보자
	if (buf->index != -1)
	{
		if (copy_static_to_string(buf, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string, ret));
	}
	read_and_copy_static_to_string(buf, &string);
	return (copy_string_to_ret_and_add_nul(&string, ret));
}