/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/15 17:47:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

// struct in main function
typedef struct s_list_of_main
{
	char	*infile_name;
	int		infile_fd;
	char	**dir_path;
	char	**execve_argv;
}	t_list;
// dir_path : include PATH= in 0, There are not / tail of string.
// execve_argv : command in 0, options from 1, NULL in last index

typedef enum e_list_of_error
{
	E_MALLOC,
	E_SYSTEM_CALL
}	t_error;

// split
typedef enum e_is_delimeter
{
	DEL_FIRST_CALL,
	DEL_YES,
	DEL_NO,
	DEL_QUOTES
}	t_delimeter;

// check error
void	check_error(t_error e, long long ret);
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
char	**ft_split_mode_quotes(char const *str, char c);

// parse_argumen
void	parse_argv(t_list *p_list, char **argv, char **envp);

// process
void	execute_process(t_list *p_list, char *envp[]);
pid_t	fork_process(void);

// control_fd
void	open_infile(t_list *p_list);
void	duplicate2_fd(t_list *p_list);

#endif
