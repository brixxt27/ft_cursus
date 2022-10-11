#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	check_malloc(void)
{
	char	*a;

	a = malloc(1);
	while (a)
		a = malloc(UINT_MAX);
	a = malloc(1);
	while (a)
		a = malloc(10000);
	a = malloc(1);
	while (a)
		a = malloc(1);
	write(1, "memory is full!\n\n", 17);
}