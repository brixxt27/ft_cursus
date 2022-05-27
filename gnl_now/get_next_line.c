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
	static t_util	*node;
	t_string		string;
	char			*ret;
	
	if (fd < 0 || BUFFER_SIZE <=0)
		return (NULL);
	if (find_node(&node, fd) == FAIL)
		return (NULL);
	if (init_string(&string) == FAIL)
		return (NULL);
	if (node->index != -1)
	{
		if (copy_static_to_string_before_eol(node, &string) == EXIST)
			return (copy_string_to_ret_and_add_nul(&string, ret));
	}
	read_and_copy_static_to_string(node, &string);
	return (copy_string_to_ret_and_add_nul(&string, ret));
}