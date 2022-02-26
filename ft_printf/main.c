#include <stdio.h>
#include "./include/ft_printf.h"
#include "./libft/libft.h"

int	main(void)
{
	int	l1;
	int	l2;

	l1 = printf("ori : %p\n", NULL);
	printf("ori len: %d\n", l1);
	l2 = ft_printf("42_ : %p\n", NULL);
	printf("42_ len: %d\n", l2);
	return (0);
}
