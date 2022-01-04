/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:07:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/04 21:12:26 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buf;

	if (!count || !size)
		return (NULL);
	buf = malloc(count * size);
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, count * size);
	return (buf);
}
