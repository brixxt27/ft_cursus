#include <unistd.h>

static int	ft_is_not_dup(char *str, char *in)
{
	while (str < in)
	{
		if (*str == *in)
			return (0);
		str++;
	}
	return (1);
}

static int	ft_is_dup(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	int		i = 0;

	if (argc == 3)
	{
		while (*(s1 + i))
		{
			if (ft_is_not_dup(s1, s1 + i) && ft_is_dup(s2, *(s1 + i)))
				write(1, s1 + i, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
