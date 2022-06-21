/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 20:32:14 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

# define CHILD 0
# define LAST_CHILD 1

// struct in main function
typedef struct s_list_of_main
{
	int		num_command;
	pid_t	pid;
	int		pipefd[2];
	char	**path;
	char	**execve_argv;
	char	**envp;
}	t_list;
// path : include PATH= in 0, There are not / tail of string.
// execve_argv : command in 0, options from 1, NULL in last index

typedef struct s_list_of_files
{
	int		input_fd;
	int		output_fd;
	char	*infile_name;
	char	*outfile_name;
}	t_files;

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

// make_pipex
void	make_pipex(t_list *plist, t_files *pfiles, int argc, char **argv);

// parse
void	parse(t_list *p_list, t_files *p_files, int argc, char **argv);
void	parse_execve_argv(t_list *p_list, int argc, int num_command, \
							char *argv[]);

// process
pid_t	fork_process(void);
int		wait_child_and_return_last_child_status(t_list *p_list, int argc);

// wrapping function about process
void	do_it_parent(t_list *p_list, t_files *p_files, int count_argc);
void	do_it_child(t_list *p_list, t_files *p_files, int count_argc);

// control_fds
void	open_infile_and_outfile(t_files *p_list);
void	duplicate2_safely(int from, int to);
void	close_safely(int fd);
void	create_pipe(t_list *p_list);

// utils_pipex
int		init_num_command(int argc);

// check error
void	check_error(t_error e, long long ret);
void	check_libft_error(char *error_str, char *mem);
void	check_fork_error(pid_t pid);
void	print_error(char *error_str);

// libft
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_malloc(void *mem);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_add_slash_strjoin(char const *s1, char const *s2);
char	**ft_split_mode_quotes(char const *str, char c);

/*
main: while 내부
	추상화 필요함. 이 전까지는 wrapping 잘 했으면서 loop 내의 logic 은 그대로 노출함.
	while loop 내 부모 프로세스에서 fork 이외에도 특정 부분에서 실패하게 된다면 무조건 wait 을 해줘야 한다.
	자식 프로세스에서 실패한 것은 바로 exit 해도 된다. exit 은 해당 프로세스만 종료 시키기 때문이다.
	fork() 에서 에러가 났을 때 wait 없이 바로 exit 해버리면 수집 되지 않은 자식 프로세스는 좀비 프로세스가 된다.

wait logic
	프로그램의 최종 exit status 는 마지막에 종료되는 프로세스가 아닌, 파이프 가장 끝 프로세스의 exit status 에 영향을 받는다.
	위의 execve loop 를 끝내고 pid 는 파이프 가장 마지막 프로세스의 id 를 가지고 있다.
	파이프는 프로세스를 병렬, 비동기로 스케줄링하여 사용하므로 어떤 프로세스가 먼저 끝날지 모른다.
	그래서 ret_wait == pid 인 경우의 status 를 가지고 있고, loop 이후에 처리해줘야 한다.(매크로 함수)

wait 이후 exit status 제어
	이 부분에서 wait 의 에러 사항 중 하나인 더 이상 기다릴 자식 프로세스가 없을 때 -1을 반환하는 점을 이용했는데 다른 에러 사항을 구분하지 못하기 때문에 위의 방법으로 바꾸었다.
		while(wait(NULL) != -1);
		check_error(E_SYSTEM_CALL, ) Think about return value of wait
	wait 의 인자인 status 를 다루는 매크로 함수를 이용하여 exit status 를 제어해준다.
*/
#endif
