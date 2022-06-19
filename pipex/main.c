/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 21:56:55 by jayoon           ###   ########.fr       */
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
	// while loop 내 부모 프로세스에서 fork 이외에도 특정 부분에서 실패하게 된다면 무조건 wait 을 해줘야 한다.
	// 자식 프로세스에서 실패한 것은 바로 exit 해도 된다. exit 은 해당 프로세스만 종료 시키기 때문이다.
	while (arguments.count_argc--)
	{
		if (arguments.count_argc != LAST_CHILD)
			create_pipe(&list);
		// fork() 에서 에러가 났을 때 wait 없이 바로 exit 해버리면 수집 되지 않은 자식 프로세스는 좀비 프로세스가 된다.
		pid = fork_process();
		if (pid == CHILD)
			do_it_child(&list, &info_files, arguments.count_argc);
		do_it_parent(&list, &info_files, arguments.count_argc);
	}
	
	// 프로그램의 최종 exit status 는 마지막에 종료되는 프로세스가 아닌, 파이프 가장 끝 프로세스의 exit status 에 영향을 받는다.
	// 위의 execve loop 를 끝내고 pid 는 파이프 가장 마지막 프로세스의 id 를 가지고 있다.
	// 파이프는 프로세스를 병렬, 비동기로 스케줄링하여 사용하므로 어떤 프로세스가 먼저 끝날지 모른다.
	// 그래서 ret_wait == pid 인 경우의 status 를 가지고 있고, loop 이후에 처리해줘야 한다.(매크로 함수)
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
	// 이 부분에서 wait 의 에러 사항 중 하나인 더 이상 기다릴 자식 프로세스가 없을 때 -1을 반환하는 점을 이용했는데 다른 에러 사항을 구분하지 못하기 때문에 위의 방법으로 바꾸었다.
	// while(wait(NULL) != -1);
	//// check_error(E_SYSTEM_CALL, ) Think about return value of wait

	// wait 의 인자인 status 를 다루는 매크로 함수를 이용하여 exit status 를 제어해준다.
	return (0);
}
