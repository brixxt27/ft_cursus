/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:45:28 by jayoon            #+#    #+#             */
/*   Updated: 2021/12/03 19:41:02 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *new_dst;
	unsigned char *new_src;

	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
	{
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		ft_memcpy(dst, src, len);
	}
	else
	{
		new_dst = (unsigned char *)dst + len - 1;
		new_src = (unsigned char *)src + len - 1;
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
