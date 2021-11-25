/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:16:53 by jayoon            #+#    #+#             */
/*   Updated: 2021/11/25 22:32:19 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	while (i < n)
	{
		if (((unsigned char *)s)1[i] != ((unsigned char *)s)2[i])
			return (((unsigned char *)s)1[i] - ((unsigned char *)s)2[i]);
	}
	return (0);
}
