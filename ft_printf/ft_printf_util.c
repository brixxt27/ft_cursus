/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:09:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/21 23:10:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c = 'X' || c == '%')
		return (1);
	return (0);
}

int     ft_print_format(va_list ap, const char *str)
{
	int len;

	len = 0;
	if (*str == 'c')
		len += ft_case_c(va_arg())
	else if (*str == 's')
	else if (*str == 'p')
	else if (*str == 'd' || *str == 'i')
	else if (*str == 'u')
	else if (*str == 'x')
	else if (*str == 'X')
	else if (*str == '%')
	else
		return (0);
}
