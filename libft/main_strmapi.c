#include <stdio.h>
#include "libft.h"

char	plus(unsigned int n, char c)
{
	c += 1;
	return (c);
}

int	main(void)
{
	char	s[] = "12345";
	char	*dp;

	dp = ft_strmapi(s, plus);
	printf("ori : %s, ft : %s\n", s, dp);
	free(dp);
	return (0);
}
