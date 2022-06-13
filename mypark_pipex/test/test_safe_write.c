/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:05:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

int	main(void)
{
	int		len;
	char	buf[3];

	len = safe_write(0, "hello\n", 6);
	printf("1st len : %d\n", len);
	len = safe_read(-1, buf, 2);
	printf("2nd len : %d\n", len);
}
