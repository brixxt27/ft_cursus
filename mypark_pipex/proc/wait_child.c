/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:52:38 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 00:43:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include "error.h"
#include "test.h"

void	wait_child(int n)
{
	int	end_cnt;
	int	stat;
	int	err;

	end_cnt = 0;
	while (end_cnt < n)
	{
		err = wait(&stat);
		err_catch(err_wait, err);
		end_cnt++;
	}
}
