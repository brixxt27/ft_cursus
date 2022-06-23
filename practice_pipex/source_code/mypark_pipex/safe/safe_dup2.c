/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:09:43 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"

int	safe_dup2(int from, int to)
{
	int	fd;

	fd = dup2(from, to);
	err_catch(err_dup, fd);
	return (fd);
}
