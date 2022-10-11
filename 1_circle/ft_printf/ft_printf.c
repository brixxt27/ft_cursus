/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:20:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/24 19:30:39 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/ft_printf.h"

static int	ft_check_format(va_list ap, const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += ft_putchar_fd(*str, 1);
		else if (*str == '%' && *(str + 1))
		{
			str++;
			if (ft_is_format(*str))
				len += ft_print_format(ap, str);
		}
		str++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (0);
	va_start(ap, format);
	len = ft_check_format(ap, format);
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	return (0);
}
*/
