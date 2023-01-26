#include <unistd.h>

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

static void	print_str(char *s1, char *s2, int idx_s1)
{
	while (*s2)
	{
		if (s1[idx_s1] == *s2)
		{
			write(1, s2, 1);
			return ;
		}
		s2++;
	}
}

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = argv[1];
	s2 = argv[2];	
	if (argc == 3)
	{
		while (s1[i])
		{
			if (!is_dup(s1, i))
				print_str(s1, s2, i);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
