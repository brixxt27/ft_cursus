/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:50:56 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_same(char *str1, char *str2)
{
	if (ft_strncmp(str1, str2, -1) == 0)
		return (1);
	return (0);
}
