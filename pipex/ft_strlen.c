#include "pipex.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (-2);
	while (str++)
		len++;
	return (len);
}
