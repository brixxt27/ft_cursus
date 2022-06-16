/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/16 20:06:42 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_argv(t_list *p_list, char *argv[])
{
	p_list->infile_name = argv[1]; 
	p_list->dir_path = NULL;
	p_list->execve_argv = ft_split(argv[2], ' ');
}

void	parse_path_in_envp(t_list *p_list, char *envp[])
{
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

void	parse(t_list *p_list, char **argv, char **envp)
{
	parse_argv(p_list, argv);
	parse_path_in_envp(p_list, envp);
}
