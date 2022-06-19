/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 15:54:49 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;
	t_files	info_files;
	t_args	arguments;

	if (argc < 5)
		print_error("Not enough argc. Input 5, including program name!\n");
	ft_set_arguments(&arguments, argc, argv, envp);
	parse(&list, &info_files, &arguments);
	open_infile_and_outfile(&info_files);
	while (arguments.count_argc--)
	{
		if (arguments.count_argc != LAST_CHILD)
			create_pipe(&list);
		pid = fork_process();
		if (pid == CHILD)
			do_it_child(&list, &info_files, arguments.count_argc);
		do_it_parent(&list, &info_files, arguments.count_argc);
	}
	while(wait(NULL) != -1);
	//check_error(E_SYSTEM_CALL, ) Think about return value of wait
	return (0);
}
