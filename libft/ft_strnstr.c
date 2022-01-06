/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:44:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/06 21:16:11 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(needle);
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + j) && i + j <= len)
	{
		if ((*(haystack + j) == *needle) && !ft_memcmp(haystack + j, needle, i))
			return ((char *)(haystack + j));
		j++;
	}
	return (NULL);
}
