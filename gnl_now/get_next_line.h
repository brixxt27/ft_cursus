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
	int		index;
} t_util;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	malloc_size;
} t_string;

typedef enum e_is_there_new_line
{
	EXIST = 0,
	NOT_EXIXT
} t_nl;

char	*get_next_line(int fd);
t_buf	*find_node(int fd);
t_nl	copy_static_to_string(t_util *buf, t_string *ps);
char	*copy_string_to_ret_and_add_nul(t_string *ps, char *ret);
void	read_and_copy_static_to_string(t_util *buf, t_string *ps);

#endif