/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 21:04:37 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>

# define CHILD 0
# define FIRST_CMD 2

// struct in main function
typedef struct s_list_of_main
{
	int		curr_idx;
	pid_t	pid;
	int		pipefd[2];
	char	**path;
	char	**execve_argv;
	char	**envp;
}	t_list;
// path : include PATH= in 0, There are not / tail of string.
// execve_argv : command in 0, options from 1, NULL in last index

typedef struct s_files
{
	int		input_fd;
	int		output_fd;
	char	*infile_name;
	char	*outfile_name;
}	t_files;

typedef enum e_error
{
	E_MALLOC,
	E_SYSTEM_CALL,
	E_NO_PATH
}	t_error;

// split, Think about DEL_QUOTES
typedef enum e_is_delimeter
{
	DEL_FIRST_CALL,
	DEL_YES,
	DEL_NO,
}	t_delimeter;

// make_pipex.c
void	make_pipex(t_list *plist, t_files *pfiles, int argc, char **argv);

// parse.c
void	parse(t_list *p_list, t_files *p_files, int argc, char **argv);
void	parse_execve_argv(t_list *p_list, \
							char *argv[]);

// process.c
pid_t	fork_safely(void);
int		wait_all_child_and_return_status(t_list *p_list);

// wrapping function about process
// do_it_parent.c
void	do_it_parent(t_list *p_list, t_files *p_files, int argc);
// do_it_child.c
void	do_it_child(t_list *p_list, t_files *p_files, int argc);

// control_fds.c
void	open_infile_or_outfile(t_list *p_list, t_files *p_files);
void	open_safely(t_files *p_files, int flag);
void	duplicate2_safely(int from, int to);
void	close_safely(int fd);
void	create_pipe(t_list *p_list);

// utils_pipex.c
void	init_utils(t_list *p_list, char **envp);
void	free_string_array(char ***p_ret);

// check error.c
void	check_error(t_error e, long long ret);
void	check_libft_error(char *error_str, char *mem);
void	check_fork_error(pid_t pid);
void	print_error(char *error_str);

// ./libft/
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_malloc(void *mem);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_add_slash_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
