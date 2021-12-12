/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:21:14 by jayoon            #+#    #+#             */
/*   Updated: 2021/12/12 16:21:37 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;

	d = (char *)s;
	while (*d != '\0')
		d++;
	while (d != s || *d == (char)c)
	{
		if (*d == (char)c)
			return (d);
		d--;
	}
	return (NULL);
}
