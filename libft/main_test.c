#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#define NUM 20

int	main(void)
{
	char	s1[NUM] = "";
	char	s2[NUM] = "";

	printf("1\n");
	printf("ft_mine :%p\n", ft_memcpy(NULL, NULL, 0));
	printf("ft_string :%s\n", s1);
	printf("origin :%p\n", memcpy(NULL, NULL, 0));
	printf("org_string :%s\n", s1);

	return (0);
}
