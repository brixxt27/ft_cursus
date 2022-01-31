/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:45:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/01 00:02:36 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s || *s == '\0')
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup_empty(void)
{
	char	*buf;

	buf = (char *)malloc(1 * sizeof(char));
	*buf = '\0';
	return (buf);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buf;
	size_t	s1_len;

	if (!s1)
		s1 = ft_strdup_empty();
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	buf = (char *)malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strcpy(buf, s1);
	ft_strcpy(buf + s1_len, s2);
	free(s1);
	return (buf);
}
