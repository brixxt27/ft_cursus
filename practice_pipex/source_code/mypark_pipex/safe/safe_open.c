/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:09:49 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "error.h"

int	safe_open(const char *file_name, int flags)
{
	int	fd;

	if (flags & O_CREAT)
		fd = open(file_name, flags, 0644);
	else
		fd = open(file_name, flags);
	err_catch(err_open, fd);
	return (fd);
}
