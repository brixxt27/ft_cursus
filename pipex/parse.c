/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 12:32:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_execve_argv(t_list *p_list, int argc, int num_command, \
							char *argv[])
{
	p_list->execve_argv = ft_split(argv[argc - num_command], ' ');
	check_libft_error("ft_split", p_list->execve_argv);
}

static void	parse_file_name(t_files *p_files, int argc, char *argv[])
{
	p_files->infile_name = argv[1];
	p_files->outfile_name = argv[argc - 1];
}

static void	parse_path_in_envp(t_list *p_list, char *envp[])
{
	p_list->envp = envp;
	p_list->path = NULL;
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			p_list->path = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
	if (p_list->path == NULL)
		print_error("Not exist path!\n");
}

void	parse(t_list *p_list, t_files *p_files, int argc, char **argv)
{
	parse_file_name(p_files, argc, argv);
	parse_path_in_envp(p_list, p_list->envp);
}
