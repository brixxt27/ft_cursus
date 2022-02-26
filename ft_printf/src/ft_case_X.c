/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:44:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 09:44:59 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"

int	ft_case_X(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, "0123456789ABCDEF");
	len = ft_case_s(str);
	free(str);
	return (len);
}
