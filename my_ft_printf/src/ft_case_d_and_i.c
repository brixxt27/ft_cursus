/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_d_and_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:31:14 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/27 00:21:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_d_and_i(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	len = ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (len);
}
