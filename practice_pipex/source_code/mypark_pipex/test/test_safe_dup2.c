/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_dup2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:06:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

int	main(void)
{
	safe_dup2(1, 3);
	printf("test 1st safe_dup2\n");
	safe_dup2(2, 5);
	printf("test 2nd safe_dup2\n");
	safe_dup2("asdfasdf", 5);
	printf("test 2nd safe_dup2\n");
	safe_dup2(-1, 0);
	printf("test 3rd safe_dup2\n");
}
