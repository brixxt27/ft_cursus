#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#define NUM 20

int	main(void)
{
	char	s1[NUM] = "999999999";
	//char	s2[NUM] = "as";
	//char	*s = 0;

	//ft_atoi(s1);
	printf("ft_mine : %p\n", ft_strrchr(s1, 0));
	//atoi(s1);
	printf("origin : %p\n", strrchr(s1, 0));

	return (0);
}
