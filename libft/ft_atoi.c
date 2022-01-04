/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:18:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/04 20:45:09 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (i < 19)
		{
			res = res * 10 + *str - '0';
			str++;
			i++;
		}
		else
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	if (res > LLONG_MAX + 1ULL && sign == -1)
		return (0);
	else if (res > LLONG_MAX && sign == 1)
		return (-1);
	return ((int)res * sign);
}
