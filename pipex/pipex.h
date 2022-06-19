/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 15:59:47 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

# define CHILD 0
# define LAST_CHILD 0

// struct in main function
typedef struct s_list_of_main
{
	int						pipefd[2];
	char					**dir_path;
	char					**execve_argv;
	char					**envp;
	struct s_list_of_main	*next;
}	t_list;
// dir_path : include PATH= in 0, There are not / tail of string.
// execve_argv : command in 0, options from 1, NULL in last index

typedef struct s_list_of_files
{
	int		input_fd;
	int		output_fd;
	char	*infile_name;
	char	*outfile_name;
}	t_files;

typedef struct s_list_of_arguments
{
	int		argc;
	int		count_argc;
	char	**argv;
	char	**envp;
}	t_args;

typedef enum e_list_of_error
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

// check error
void	check_error(t_error e, long long ret);
void	check_libft_error(char *error_str, char *mem);
void	check_fork_error(pid_t pid);
void	print_error(char *error_str);

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
void	ft_set_arguments(t_args *p_args, int argc, char **argv, char **envp);

// parse_arguments
void	parse(t_list *p_list, t_files *p_files, t_args *p_args);

// process
void	do_it_parent(t_list *p_list, t_files *p_files, int count_argc);
void	do_it_child(t_list *p_list, t_files *p_files, int count_argc);
// void	execute_process(t_list *p_list);
pid_t	fork_process(void);

// control_fd
void	open_infile_and_outfile(t_files *p_list);
void	duplicate2_safely(int from, int to);
void	close_file(t_files *p_files);
void	create_pipe(t_list *p_list);

#endif
