/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:16:53 by jayoon            #+#    #+#             */
/*   Updated: 2021/12/11 19:20:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*dst2;
	size_t			i;

	dst1 = (unsigned char *)s1;
	dst2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (dst1[i] != dst2[i])
			return (dst1[i] - dst2[i]);
	return (0);
}
