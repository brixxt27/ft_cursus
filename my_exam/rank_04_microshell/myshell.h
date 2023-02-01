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

enum e_type
{
	e_null,
	e_pipe,
	e_semicolon
};

typedef struct s_execve_info
{
	char*		path;
	char**		argv;
	char**		envp;
	enum e_type	curr_type;
	enum e_type	prev_type;
}	t_execve_info;

typedef struct s_pipe_fd
{
	int	curr_pipe[2];
	int	prev_read_pipe;
}	t_pipe;

//enum e_isword {
//	e_noword,
//	e_yesword
//};

#endif
