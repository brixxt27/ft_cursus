/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:06:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

int	main(void)
{
	safe_close(3);
	safe_write(1, "safe_close 1st done\n", 21);
	safe_write(2, "safe_close 1st done\n", 21);
	safe_close(-1);
	printf("safe_close 2nd done\n");
}
