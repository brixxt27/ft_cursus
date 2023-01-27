#include "unistd.h"

static int	is_dup(char *s, int i)
{
	int	j;
	
	j = 0;
	while (j < i)
	{
		if (s[j] == s[i])
			return (1);
		j++;
	}
	return (0);
}

static int	is_not_dup(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	int		i1;

	i1 = 0;
	s1 = argv[1];
	s2 = argv[2];
	if (argc == 3)
	{
		while (s1[i1])
		{
			if (!is_dup(s1, i1))
				write(1, &s1[i1], 1);
			i1++;
		}
		i1 = 0;
		while (s2[i1])
		{
			if (is_not_dup(s1, s2[i1]) && !is_dup(s2, i1))
				write(1, &s2[i1], 1);
			i1++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
