#include "microshell.h"
#include <string.h>

int	init_execve_info(char** argv, t_execve_info* execve_info, int last_argv_idx)
{
	int i = last_argv_idx + 1;

	execve_info->path = argv[i];
	execve_info->argv = &argv[i];
	while (argv[i]) {
		if (argv[i + 1] == NULL || strncmp(argv[i + 1], "|", 1) == 0 || strncmp(argv[i + 1], ";", 1) == 0) {
			if (argv[i + 1] == NULL)
				execve_info->type = e_null;
			else if (strncmp(argv[i + 1], "|", 1) == 0)
				execve_info->type = e_pipe;
			else
				execve_info->type = e_semicolon;
			argv[i + 1] = NULL;
		}
		i++;
	}
}

int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info = {
									NULL,
									NULL,
									envp,
									e_null
	};
	int	i = 0;
	int	last_argv_idx = 0;

	if (argc < 2)
		return 0;
	
	while (argv[i] != NULL) {
		last_argv_idx = init_execve_info(argv, &execve_info, last_argv_idx);
		i++;
	}
}
