#include "pipex.h"

void	ft_free_malloc(void *mem)
{
	free(mem);
	mem = NULL;
}
