#include "pipex.h"

void	check_error(t_error e, void *mem)
{
	if (e == E_MALLOC && !mem)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
}
