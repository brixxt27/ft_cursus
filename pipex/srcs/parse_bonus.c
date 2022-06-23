/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 21:56:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parse_execve_argv(t_list *p_list, \
							char *argv[])
{
	p_list->execve_argv = ft_split(argv[p_list->curr_idx], ' ');
	check_libft_error("ft_split", (char *)p_list->execve_argv);
}

static void	parse_file_name(t_files *p_files, int argc, char *argv[])
{
	p_files->infile_name = argv[1];
	p_files->outfile_name = argv[argc - 1];
}

static char	*delete_path_word(char *str)
{
	char	*tmp;

	tmp = ft_strdup(str + 5);
	check_libft_error("ft_strdup", tmp);
	ft_free_malloc(str);
	return (tmp);
}

static void	parse_path_in_envp(t_list *p_list, char *envp[])
{
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
	p_list->path[0] = delete_path_word(p_list->path[0]);
}

void	parse(t_list *p_list, t_files *p_files, int argc, char **argv)
{
	parse_file_name(p_files, argc, argv);
	parse_path_in_envp(p_list, p_list->envp);
}
