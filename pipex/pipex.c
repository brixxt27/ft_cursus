/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/14 01:16:39 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/*
	//순서
	명령행 인자로 프로세스와 옵션 받기
	파싱하기
	fork 하기
	자식 프로세스로 프로세스 실행하기
	끝

	//형식
	./pipex "ls -al"
	*/
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	parse_argv(t_list *p_list, char **argv, char **envp)
{
	p_list->dir_path = NULL;
	p_list->execve_argv = ft_split(argv[1], ' ');
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			p_list->dir_path = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
	if (p_list->dir_path == NULL)
		print_err("Not exist path!\n");
	// p_list->dir_path[0] 에서 "PATH=" 빼고 각 요소 끝에 / 붙이기
	// execve 하는 함수에서 strjoin 으로 하는 과정에서 바꿔줘야겠다.
}

int	main(int argc, char *argv[], char *envp[])
{
	// pid_t 	pid;
	t_list	list;

	if (argc < 2) // 프로그램 이름, 명령어와 옵션 포함한 문자열
		print_err("Not enough argc!\n");
	parse_argv(&list, argv, envp);
	// p_list->dir_path[0] 에서 "PATH=" 빼고 각 요소 끝에 / 붙이기
	/*
	pid = fork;
	if (pid == 0)
		proc_child();
	wait(NULL);
	execve("/bin/ls", argv, envp);
	*/
	return (0);
}
