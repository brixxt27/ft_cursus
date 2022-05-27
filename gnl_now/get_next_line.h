#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_util
{
	int		fd;
	char	buf[BUFFER_SIZE];
	char	*cur;
	char	*end;
} t_util;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	malloc_size;
} t_string;

#endif