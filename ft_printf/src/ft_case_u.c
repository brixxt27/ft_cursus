/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:39:02 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 09:56:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_u(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, DECIMAL_BASE);
	len = ft_case_s(str);
	free(str);
	return (len);
}
