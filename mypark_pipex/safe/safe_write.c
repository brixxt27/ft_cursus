/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:09:53 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 17:23:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"

int	safe_write(int fd, const void *buf, size_t size)
{
	int	len;

	len = write(fd, buf, size);
	err_catch(err_write, len);
	return (len);
}
