/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_slash_strjoin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:49:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/14 16:08:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	add_slash_strcpy(char *dst, char const *src)
{
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '/';
	*(++dst) = '\0';
}

char	*ft_add_slash_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	add_slash_strcpy(str, s1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}