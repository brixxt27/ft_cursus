#include <stdlib.h>
#include "pipex.h"

void	*allocate_memory(int size, int count)
{
	void	*mem;

	mem = malloc(size * count);
	check_error(E_MALLOC, mem);
	return (mem);
}
