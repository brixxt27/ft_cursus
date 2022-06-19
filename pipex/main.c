/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 20:58:38 by jayoon           ###   ########.fr       */
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
		print_error("Not input enough arguments! Need to 5.\n");
	ft_set_arguments(&arguments, argc, argv, envp);
	// data 를 그대로 가지고 있을 필요가 없음. while 내부에서 execve 할 때마다 기존 변수에 값을 덮어씌우는 방식으로 할 거임.
	parse(&list, &info_files, &arguments);
	open_infile_and_outfile(&info_files);
	// 추상화 필요함. 이 전까지는 wrapping 잘 했으면서 loop 내의 logic 은 그대로 노출함.
	while (arguments.count_argc--)
	{
		if (arguments.count_argc != LAST_CHILD)
			create_pipe(&list);
		pid = fork_process();
		if (pid == CHILD)
			do_it_child(&list, &info_files, arguments.count_argc);
		do_it_parent(&list, &info_files, arguments.count_argc);
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
	while(wait(NULL) != -1);
	//check_error(E_SYSTEM_CALL, ) Think about return value of wait
	return (0);
}
