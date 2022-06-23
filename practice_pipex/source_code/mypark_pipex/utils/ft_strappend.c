/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:44:15 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*ft_strappend(char const *s1, char const *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free((void *)s1);
	return (s3);
}
