/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:30 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 20:07:18 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	path = parse_env(envp, "PATH");
	free(path);
	while (1)
		;
}
