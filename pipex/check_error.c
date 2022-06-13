/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/13 10:27:21 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_error(t_error e, void *mem)
{
	if (e == E_MALLOC && !mem)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
}
