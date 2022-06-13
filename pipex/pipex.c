/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/13 10:46:10 by jayoon           ###   ########.fr       */
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

int		print_err(const char *str);
void	parse_argv(t_list *p_list, char **argv, char **envp);
// void	proc_child(void);

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;

	if (argc < 2) // 프로그램 이름, 명령어와 옵션 포함한 문자열
		print_err("argc");
	parse_argv(&list, argv, envp);
	// pid = fork();
	// if (pid == 0)
	// 	proc_child();
	// wait(NULL);
	execve("/bin/ls", argv, envp);
	return (0);
}

int		print_err(const char *str)
{
	perror(str);
	exit(1);
}

void	parse_argv(t_list *p_list, char **argv, char **envp)
{
	char	*path;

	path = NULL;
	p_list->execve_argv = ft_split(argv[1], ' ');
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			path = *envp;
	}
	if (path == NULL)

	// execve_argv[0] 앞에 붙여 넣으며 존재하는 명령어인지 확인
	// if 있으면 실행
	// else 에러 메시지 띄우며 종료 
}