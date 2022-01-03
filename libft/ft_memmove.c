/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:45:28 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/03 16:56:03 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst - src < len)
	{
		while (i >= 0)
		{
			i = len - 1;
			dst[i] = src[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
