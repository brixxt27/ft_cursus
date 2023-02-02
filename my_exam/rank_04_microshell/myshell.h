#ifndef MYSHELL_H
#define MYSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//err
#include <stdio.h>

#define STDIN	0
#define	STDOUT	1
#define	STDERR	2

enum e_cmd_type
{
	TYPE_NULL,
	TYPE_PIPE,
	TYPE_SEMICOLON
};

typedef struct s_execve_info
{
	char*			path;
	char**			argv;
	char**			envp;
	enum e_cmd_type	curr_type;
	enum e_cmd_type	prev_type;
}	t_execve_info;

typedef struct s_pipe_fd
{
	int	curr_pipe[2];
	int	prev_read_pipe;
}	t_pipe;

#endif
