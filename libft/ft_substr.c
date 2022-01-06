/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:12:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/06 22:15:47 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		while (i < len)
		{
			if (s[i] == '\0')
				break ;
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
