/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/14 00:49:52 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>

// struct in main function
typedef struct s_list_of_main
{
	char	**dir_path;
	char	**execve_argv;
}	t_list;

typedef enum e_list_of_error
{
	E_MALLOC
}	t_error;

// split
typedef enum e_is_delimeter
{
	DEL_FIRST_CALL,
	DEL_YES,
	DEL_NO
}	t_delimeter;

// check error
void	check_error(t_error e, void *mem);

// libft.h
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
void	print_err(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// parse
void	parse_argv(t_list *p_list, char **argv, char **envp);

#endif
