/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 19:06:54 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_list	list;
	t_files	info_files;
	int 	status;
	int		cnt;

	if (argc < 5)
		print_error("Input is not enough!\n");
	cnt = 0;
	list.num_command = init_num_command(argc);
	parse(&list, &info_files, argc, argv);
	open_infile_and_outfile(&info_files);
	make_pipex(&list, &info_files, argc, argv);
	while (1)
	{
		if (wait(&status) != -1)
			cnt++;
		if (wait_ret == list.pid)
			process_ret = status;
		if (cnt == argc - 3)
			break ;
	}
	return (0);
}
