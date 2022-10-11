#include <stdio.h>
#include "./include/ft_printf.h"

int	main(void)
{
	int	l1;
	int	l2;
	char	*str = "im_string";
	char	c = 'c';

	l1 = ft_printf("%c %s %d %i string %p %u %x %X %%\n", c, str, 42, 42, str, 42, 42, 42);
	l2 = printf("%c %s %d %i string %p %u %x %X %%\n", c, str, 42, 42, str, 42, 42, 42);
	printf("%d %d\n", l1, l2);
	return (0);
}
