/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/16 21:05:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h> // 이건 왜 필요하지??
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;
	t_args	arguments;
	t_files	info_files;

	if (argc < 4)
		print_error("Not enough argc. Input 3, including program name!\n");
	set_arguments(&arguments, argc, argv, envp);
	parse(&list, &arguments, &info_files);
	open_infile(&info_files);
	pid = fork_process();
	if (pid == 0)
	{
		duplicate2_fd(&info_files);
		execute_process(&list, envp);
	}
	close_file(&info_files);
	wait(NULL);
	return (0);
}
