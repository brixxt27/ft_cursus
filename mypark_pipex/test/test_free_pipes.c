/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:24 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:07:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include "proc.h"
#include "test.h"

int	main(void)
{
	t_proc_info	info;

	info.max_fork = 10;
	alloc_pipes(&info);
	free_pipes(&info);
	while (1)
		;
}
