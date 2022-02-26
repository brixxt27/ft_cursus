/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:19:07 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 09:55:47 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_p(void *ptr)
{
	int					len;
	char				*str_base;
	unsigned long long	address;

	len = ft_putstr_fd("0x", 1);
	address = (unsigned long long)ptr;
	str_base = ft_itoa_base(address, L_BASE_16);
	len += ft_putstr_fd(str_base, 1);
	free(str_base);
	return (len);
}
