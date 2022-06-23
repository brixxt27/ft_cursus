/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:16 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 21:02:08 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*allocate_memory(int size, int count)
{
	void	*mem;

	mem = malloc(size * count);
	check_error(E_MALLOC, (long long)mem);
	return (mem);
}
