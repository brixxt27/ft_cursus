/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/17 00:50:04 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

void	do_it_child(t_list *p_list, t_files *p_files)
{
	duplicate2_fd(p_files);
	execute_process(p_list);
}

void	do_it_parent(t_files *p_files)
{
	close_file(p_files);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;
	t_args	arguments;
	t_files	info_files;

	if (argc < 4)
		print_error("Not enough argc. Input 3, including program name!\n");
	set_arguments(&arguments, argc, argv, envp);
	parse(&list, &arguments);
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
