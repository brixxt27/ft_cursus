/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:05:23 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/16 19:21:53 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_format(va_list ap, const char *str)
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
