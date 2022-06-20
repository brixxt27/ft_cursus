/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:58:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/20 21:39:35 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

// wait 해줘야 한다.
pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	check_fork_error(pid);
	return (pid);
}
