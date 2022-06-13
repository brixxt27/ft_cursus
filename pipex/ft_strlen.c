/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:29 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/13 10:27:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (-2);
	while (str++)
		len++;
	return (len);
}
