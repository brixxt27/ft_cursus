/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:09:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/25 17:45:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c = 'X' || c == '%')
		return (1);
	return (0);
}

int     ft_print_format(va_list ap, char c)
{
	int len;

	len = 0;
	if (c == 'c')
		len = ft_case_c(va_arg(ap, int));
	else if (c == 's')
		len = ft_case_s(va_arg(ap, char *));
	else if (c == 'p')
		len = ft_case_p(va_arg(ap, void *));
	else if (c == 'd' || *str == 'i')
		len = ft_case_d_of_i(va_arg(ap, int));
	else if (c == 'u')
		len = ft_case_u(va_arg(ap, int));
	else if (c == 'x')
		len = ft_case_x(va_arg(ap, unsigned long long));
	else if (c == 'X')
		len = ft_case_X(va_arg(ap, unsigned long long));
	else if (c == '%')
		len = ft_case_percent(va_arg(ap, int));
	return (len);
}
