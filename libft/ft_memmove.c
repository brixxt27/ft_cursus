/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:45:28 by jayoon            #+#    #+#             */
/*   Updated: 2021/12/11 19:39:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		i = 0;
		new_dst = (unsigned char *)dst + len - 1;
		new_src = (unsigned char *)src + len - 1;
		while (i < len)
		{
			*new_dst-- = *new_src--;
			i++;
		}
	}
	return (dst);
}
