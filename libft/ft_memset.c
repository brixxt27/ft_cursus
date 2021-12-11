/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:58:24 by jayoon            #+#    #+#             */
/*   Updated: 2021/12/11 16:18:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	ch;

	dest = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		dest[i] = ch;
		i++;
	}
	return (b);
}
