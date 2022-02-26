/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:50:11 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 05:28:10 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_integer(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(long long n_ll)
{
	if (n_ll < 0)
		return (1);
	return (0);
}

static void	set_string(char *str, long long n_ll, int len_int)
{
	int flag;

	flag = 0;
	str[len_int--] = '\0';
	if (is_negative(n_ll))
	{
		n_ll *= -1;
		flag = 1;
	}
	while (len_int >= 0)
	{
		str[len_int--] = n_ll % 10 + '0';
		n_ll /= 10;
	}
	if (flag)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len_int;
	long long	n_ll;

	n_ll = n;
	len_int = get_len_integer(n_ll);
	if (is_negative(n_ll))
		len_int++;
	str = (char *)malloc((len_int + 1) * sizeof(char));
	if (!str)
		return (NULL);
	set_string(str, n_ll, len_int);
	return (str);
}
