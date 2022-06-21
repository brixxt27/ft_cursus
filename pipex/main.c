/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 12:33:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	int		num_command;
	t_list	list;
	pid_t 	pid;
	t_files	info_files;

	if (argc < 5)
		print_error("Input is not enough!\n");
	num_command = init_num_command(argc);
	parse(&list, &info_files, argc, argv);
	open_infile_and_outfile(&info_files);
	while (num_command)
	{
		parse_execve_argv(&list, argc, num_command, argv);
		if (num_command != LAST_CHILD)
			create_pipe(&list);
		pid = fork_process();
		if (pid == CHILD)
			do_it_child(&list, &info_files, num_command);
		do_it_parent(&list, &info_files, num_command);
		--num_command;
	}
	int status;
	while (1)
	{
		if wait(&status) != -1
			cnt++
		if wait_ret == pid
			process_ret = status;
		if (cnt == argc - 3)
			break ;
	}
	return (0);
}
