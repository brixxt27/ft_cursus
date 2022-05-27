/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_upper_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:27:50 by jayoon            #+#    #+#             */
/*   Updated: 2022/03/01 15:45:35 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_upper_x(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, U_BASE_16);
	len = ft_case_s(str);
	free(str);
	str = NULL;
	return (len);
}
