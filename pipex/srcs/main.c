/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 12:01:00 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

// test
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_list	list;
	t_files	info_files;
	int		last_child_status;

	if (argc < 5)
		print_error("Input is not enough!\n");
	list.curr_idx = 2;
	init_utils(&list, envp);
	parse(&list, &info_files, argc, argv);
	open_infile_and_outfile(&info_files);
	make_pipex(&list, &info_files, argc, argv);
	last_child_status = wait_child_and_return_last_child_status(&list, argc);
	return (WEXITSTATUS(last_child_status));
}
