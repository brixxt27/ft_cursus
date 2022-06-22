/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:13:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 21:56:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*buf;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, len + 1);
	return (buf);
}
