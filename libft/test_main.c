#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char s1[10] = "1";
	char s2[20] = "1234567";

	printf("result : %zu\n", ft_strlcat(s1, s2, 7));
	ft_strlcat(s1, s2, 7);
	printf("ft_mine : %s\n", s1);
	strlcat(s1, s2, 7);
	printf("origin : %s\n", s1);
	return (0);
}
