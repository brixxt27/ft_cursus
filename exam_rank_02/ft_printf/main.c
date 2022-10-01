#include <stdio.h>

int	ft_printf(const char *fmt, ... );

int	main(void)
{
	int	len;

	len = ft_printf("%d\n", 2147483649);
	printf("len is %d\n", len);


	len = ft_printf("%x\n", 4294967296);
	printf("len is %d\n", len);


	len = ft_printf("%s\n", "123456789");
	printf("len is %d\n", len);
	// printf("%d %d\n", -4 / 10, -4 % 10);
	return (0);
}
