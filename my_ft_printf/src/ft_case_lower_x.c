/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_lower_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:31:28 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 10:32:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_lower_x(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, L_BASE_16);
	len = ft_case_s(str);
	free(str);
	return (len);
}
