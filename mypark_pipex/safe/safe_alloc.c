/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:37:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:54:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"

void	*safe_malloc(int size, int count)
{
	void	*mem;

	mem = malloc(size * count);
	err_catch(err_alloc, (long int)mem);
	return (mem);
}
