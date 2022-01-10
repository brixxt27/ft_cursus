#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	**tab;
	size_t	i;

	i = 0;
	tab = ft_split("              olol", ' ');
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
	return (0);
}
