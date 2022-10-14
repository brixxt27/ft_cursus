#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_zone
{
	int		width;
	int		height;
	char	c;
}	t_zone;

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

static int	parse_zone(FILE *file, t_zone *zone)
{
	return (fscanf(file, "%d %d %c", &zone->width, &zone->height, &zone->c));
}

static void	print_arr(char **arr, t_zone *zone)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static char **init_form(t_zone *zone)
{
	char	**form;
	int		i;
	int		j;

	i = 0;
	form = malloc(sizeof(char *) * zone->height);
	while (i < zone->height)
	{
		form[i] = malloc(sizeof(char) * zone->width);
		j = 0;
		while (j < zone->width)
		{
			form[i][j] = zone->c;
			j++;
		}
		i++;
	}
	// print_arr(form, zone);
	return (form);
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	char	**form;
	t_zone	zone;

	if (argc == 2)
	{
		file = fopen_file(argv[1]);
		if (file == NULL)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		if (parse_zone(file, &zone) != 3)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		form = init_form(&zone);
		// parse_rect
	}
	else
		ft_putstr("Error: argument\n");
	return (0);
}
