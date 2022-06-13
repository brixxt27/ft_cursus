/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_exe_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:54:46 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 01:58:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "pipe.h"
#include "safe.h"
#include "error.h"
#include "utils.h"
#include <unistd.h>
#include "test.h"

static void	execute_cmd(char **paths, char **cmd_args, char **envp)
{
	int		i;

	if (access((const char *)cmd_args[0], X_OK) == 0)
		safe_execve(cmd_args[0], cmd_args, envp);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strappend(paths[i], "/");
		paths[i] = ft_strappend(paths[i], cmd_args[0]);
		if (access((const char *)paths[i], X_OK) == 0)
			safe_execve(paths[i], cmd_args, envp);
		i++;
	}
	perror("command not found");
}

void	proc_exe_cmd(t_proc_info *info)
{
	char	**cmd_args;
	char	**paths;
	char	*env_path;

	safe_dup2(info->pipes[info->ch_num][0], 0);
	safe_dup2(info->pipes[info->ch_num][1], 1);
	close_pipes(info);
	free_pipes(info);
	cmd_args = ft_split(info->cmd, ' ');
	err_catch(err_alloc, (long int)cmd_args);
	env_path = parse_env(info->envp, "PATH");
	paths = ft_split(env_path, ':');
	err_catch(err_alloc, (long int)paths);
	execute_cmd(paths, cmd_args, info->envp);
	free_words(paths);
	free_words(cmd_args);
	free(env_path);
}
