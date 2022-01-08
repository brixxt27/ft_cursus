#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	**tab;
	size_t	i;

	i = 0;
	tab = ft_split("sd sds d asd", ' ');
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	system("leaks a.out");
	return (0);
}
