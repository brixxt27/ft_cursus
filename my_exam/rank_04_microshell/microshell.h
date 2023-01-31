#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <stdlib.h>

#define STDIN	0
#define	STDOUT	1
#define	STDERR	2

enum e_type
{
	e_pipe,
	e_semicolon,
	e_null
};

typedef struct s_execve_info
{
	char*		path;
	char**		argv;
	char**		envp;
	enum e_type	type;
}	t_execve_info;

typedef struct s_pipe_fd
{
	int	pipe_fd[2];
	int	past_fd;
}	t_pipe;

//enum e_isword {
//	e_noword,
//	e_yesword
//};

#endif
