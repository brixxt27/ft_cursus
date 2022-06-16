/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/17 01:11:44 by jayoon           ###   ########.fr       */
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

	if (argc < 4)
		print_error("Not enough argc. Input 3, including program name!\n");
	ft_set_arguments(&arguments, argc, argv, envp);
	parse(&list, &info_files, &arguments);
	open_infile_and_outfile(&info_files);
	while (argc-- - 3)
	{
		create_pipe(&list);
		pid = fork_process();
		if (pid == CHILD)
			do_it_child(&list, &info_files);
		do_it_parent(&info_files);
	}
	while(wait(NULL) != -1);
	//check_error(E_SYSTEM_CALL, )
	return (0);
}
