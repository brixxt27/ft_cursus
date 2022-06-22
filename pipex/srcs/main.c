/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 21:56:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_list	list;
	t_files	info_files;
	int		last_child_status;

	if (argc < 5)
		print_error("Input is not enough!\n");
	init_utils(&list, envp);
	parse(&list, &info_files, argc, argv);
	make_pipex(&list, &info_files, argc, argv);
	last_child_status = wait_child_and_return_last_child_status(&list, argc);
	return (WEXITSTATUS(last_child_status));
}
