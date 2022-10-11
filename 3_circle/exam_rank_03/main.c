#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_back
{
	int		width;
	int		height;
	char	c;
}	t_back;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;	
}	t_rect;

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		++len;
		++s;
	}
	return (len);
}

static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static FILE	*fopen_file(char *path)
{
	FILE	*file;

	file = fopen(path, "r");
	return (file);
}

static int	init_back(FILE *file, t_back *back)
{
	return (fscanf(file, "%d %d %c", &back->width, &back->height, &back->c));
}

static void	print_arr(char **arr, t_back *back)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < back->width)
	{
		j = 0;
		while (j < back->width)
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static char **init_form(t_back *back)
{
	char	**form;
	int		i;
	int		j;

	i = 0;
	form = malloc(sizeof(char *) * back->height);
	while (i < back->width)
	{
		form[i] = malloc(sizeof(char) * back->width);
		j = 0;
		while (j < back->width)
		{
			form[i][j] = back->c;
			j++;
		}
		i++;
	}
	// print_arr(form, back);
	return (form);
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	char	**form;
	t_back	back;

	if (argc == 2)
	{
		file = fopen_file(argv[1]);
		if (file == NULL)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		if (init_back(file, &back) != 3)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		form = init_form(&back);
	}
	else
		ft_putstr("Error: argument\n");
	return (0);
}
