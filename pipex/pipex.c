/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/15 18:15:01 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	open_infile(t_list *p_list)
{
	p_list->infile_fd = open(p_list->infile_name, O_RDONLY);
	check_error(E_SYSTEM_CALL, (long long)p_list->infile_fd);
}

void	duplicate2_fd(t_list *p_list)
{
	int	fd;

	fd = dup2(p_list->infile_fd, 0);
	check_error(E_SYSTEM_CALL, (long long)fd);
}

void	close_file(t_list *p_list)
{
	close(p_list->infile_fd);
	check_error(E_SYSTEM_CALL, (long long)p_list->infile_fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;

	if (argc < 3)
		print_error("Not enough argc. Input 3, including program name!\n");
	parse_argv(&list, argv, envp);
	open_infile(&list);
	pid = fork_process();
	if (pid == 0)
	{
		duplicate2_fd(&list);
		execute_process(&list, envp);
	}
	close_file(&list);
	wait(NULL);
	return (0);
}
