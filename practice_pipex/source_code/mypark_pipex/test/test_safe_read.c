/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:05:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

/* access, not exist */

int	main(void)
{
	int		len;
	char	buf[3];

	len = safe_read(0, buf, 2);
	buf[len] = '\0';
	printf("1st len : %d buf : %s", len, buf);
	len = safe_read(-1, buf, 2);
	buf[len] = '\0';
	printf("2nd len : %d buf : %s", len, buf);
}
