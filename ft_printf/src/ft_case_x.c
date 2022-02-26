/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:42:54 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 09:44:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_x(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, "0123456789abcdef");
	len = ft_case_s(str);
	free(str);
	return (len);
}
