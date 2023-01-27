#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <stdlib.h>

#define FT_STDIN	0
#define	FT_STDOUT	1
#define	FT_STDERR	2

typedef struct s_execve_info {
	char*	path;
	char**	argv;
	int		path_size;
}	t_execve_info;

enum e_isword {
	e_noword,
	e_yesword
};

#endif
