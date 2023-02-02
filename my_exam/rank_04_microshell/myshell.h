#ifndef MYSHELL_H
#define MYSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//err
#include <stdio.h>

enum e_standard_fd
{
	kStdin,
	kStdout,
	kStderr
};

enum e_cmd_type
{
	kNull,
	kPipe,
	kSemicolon
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
