/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:43:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 23:50:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

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
				len += ft_print_format(ap, *str);
			else
				len += ft_putchar_fd(*str, 1);
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
