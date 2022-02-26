/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_upper_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:27:50 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/27 00:22:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_upper_x(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, "0123456789ABCDEF");
	len = ft_case_s(str);
	free(str);
	str = NULL;
	return (len);
}
