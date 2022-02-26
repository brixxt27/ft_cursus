/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:01:58 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 11:27:50 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_case_s(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_putstr_fd(str, 1);
	return (len);
}
