/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/16 21:06:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_file_name(t_files *p_list, int argc, char *argv[])
{
	p_list->infile_name = argv[1]; 
	p_list->outfile_name = argv[argc - 1];
}

static void	parse_argv(t_list *p_list, int argc, char *argv[])
{
	p_list->execve_argv = ft_split(argv[2], ' ');
}

static void	parse_path_in_envp(t_list *p_list, char *envp[])
{
	p_list->dir_path = NULL;
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
}

void	parse(t_list *p_list, t_args *p_args, t_files *p_info)
{
	parse_file_name(p_info, p_args->argc, p_args->argv);
	parse_execve_argv(p_list, p_args->argc, p_args->argv);
	parse_path_in_envp(p_list, p_args->envp);
}
