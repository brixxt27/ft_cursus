/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:16:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/12 10:13:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static char	**free_substr_error(char **s, size_t last_i)
{
	size_t	i;

	i = 0;
	while (i <= last_i && s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**allocate_values(char **str, char const *s, char c)
{
	size_t	i;
	char	*from;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				s++;
			str[i] = ft_substr(from, 0, s - from);
			if (str[i] == NULL)
				return (free_substr_error(str, i));
			i++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str)
		return (NULL);
	str = allocate_values(str, s, c);
	return (str);
}
