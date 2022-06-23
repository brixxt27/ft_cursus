/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_safe_execve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:34 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 01:19:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe.h"
#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	printf("test 1st safe_execve\n");
	safe_execve("a", argv, envp);
}
