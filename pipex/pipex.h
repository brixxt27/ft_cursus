/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/15 15:52:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

// struct in main function
typedef struct s_list_of_main
{
	char	*infile;
	// include PATH= in 0, There are not / tail of string.
	char	**dir_path;
	// command in 0, options from 1, NULL in last index
	char	**execve_argv;
}	t_list;

typedef enum e_list_of_error
{
	E_MALLOC,
	E_SYSTEM
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
void	check_fork_error(pid_t pid);
void	print_error(char *str);

// libft.h
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_malloc(void *mem);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_add_slash_strjoin(char const *s1, char const *s2);

// parse
void	parse_argv(t_list *p_list, char **argv, char **envp);

// process
void	execute_process(t_list *p_list, char *envp[]);
pid_t	fork_process(void);

// file
void	open_infile(t_list p_list);

#endif
