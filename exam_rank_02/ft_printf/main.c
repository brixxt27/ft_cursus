#include <stdio.h>

int	ft_printf(const char *fmt, ... );

int	main(void)
{
	int	len;

	len = ft_printf("%d, %x\n", 2147483649, 2147483647);
	printf("len is %d\n", len);
	// printf("%d %d\n", -4 / 10, -4 % 10);
	return (0);
}
