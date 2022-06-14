/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:56 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/14 20:43:21 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		print_error("Not exist path!\n");
	// p_list->dir_path[0] 에서 "PATH=" 빼고 각 요소 끝에 / 붙이기
	// execve 하는 함수에서 strjoin 으로 하는 과정에서 바꿔줘야겠다.
}

void	execute_process(t_list *p_list, char *envp[])
{
	size_t	i;
	char	*path;

	i = 0;
	while (p_list->dir_path[i])
	{
		if (i == 0)
			path = ft_add_slash_strjoin(p_list->dir_path[i] + 5, \
									p_list->execve_argv[0]);
		else
			path = ft_add_slash_strjoin(p_list->dir_path[i], \
									p_list->execve_argv[0]);
		check_error(E_MALLOC, path);
		execve(path, p_list->execve_argv, envp);
		ft_free_malloc(path);
		i++;
	}
	print_error("Execve can't execute!\n");
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	check_fork_error(pid);
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t 	pid;
	t_list	list;

	if (argc < 2)
		print_error("Not enough argc!\n");
	parse_argv(&list, argv, envp);
	pid = fork_process();
	if (pid == 0)
		execute_process(&list, envp);
	wait(NULL);
	return (0);
}
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
