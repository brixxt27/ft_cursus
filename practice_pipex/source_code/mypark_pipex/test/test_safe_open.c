/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:06:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

/* access, not exist */

int	main(void)
{
	int	fd;

	fd = safe_open("hey", O_RDONLY);
	printf("test 1st open fd : %d\n", fd);
	fd = safe_open("a.txt", O_RDONLY);
	printf("test 2nd open fd : %d\n ", fd);
}
