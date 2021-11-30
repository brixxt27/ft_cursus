#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#define NUM 20

int	main(void)
{
	char	s1[NUM] = "21474836499999999999";
	//char	s2[NUM] = "as";
	//char	*s = 0;

	ft_atoi(s1);
	printf("ft_mine : %d\n", ft_atoi(s1));
	atoi(s1);
	printf("origin : %d\n", atoi(s1));

	return (0);
}
