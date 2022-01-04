/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:18:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/05 00:43:07 by jayoon           ###   ########.fr       */
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

static int	check_isspace_and_sign(const char *str, int sign)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (sign);
}

static void	cal_result(const char *str, unsigned long long *res)
{
	*res = *res * 10 + *str - '0';
	str++;
}

int	ft_atoi(const char *str)
{
	int					sign_i[2];
	unsigned long long	res;

	sign_i[0] = 1;
	sign_i[1] = 0;
	res = 0;
	sign_i[0] = check_isspace_and_sign(str, sign_i[0]);
	while (ft_isdigit(*str))
	{
		if (sign_i[1] < 19)
			cal_result(str, &res);
		else
		{
			if (sign_i[0] == -1)
				return (0);
			else
				return (-1);
		}
		sign_i[1]++;
	}
	if (res > LLONG_MAX + 1ULL && sign_i[0] == -1)
		return (0);
	else if (res > LLONG_MAX && sign_i[0] == 1)
		return (-1);
	return ((int)res * sign_i[0]);
}
