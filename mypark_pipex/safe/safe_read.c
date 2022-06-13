/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:09:53 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 17:29:56 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"

int	safe_read(int fd, void *buf, size_t size)
{
	int	len;

	len = read(fd, buf, size);
	err_catch(err_read, len);
	return (len);
}
