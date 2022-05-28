#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_util
{
	int				fd;
	char			buf[BUFFER_SIZE];
	int				index;
	struct s_util	*next;
} t_util;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	malloc_size;
} t_string;

typedef enum e_is_there_eol
{
	EXIST = 0,
	NOT_EXIST
} t_eol;

typedef enum e_status
{
	SUCCESS = 0,
	FAIL
} t_status;

char		*get_next_line(int fd);
t_eol		copy_static_to_string(t_util *curr, t_string *ps);
char		*copy_string_to_ret_and_add_nul(t_string *ps);
void		read_and_copy_static_to_string(int fd, t_util *curr, t_string *ps);

t_status	find_node(int fd, t_util *head, t_util **pcurr);
t_status	init_string(t_string *ps);
char		*delete_current_node(t_util **pn);
char		*delete_all_node(t_util **pn);

/*
char		*get_next_line(int fd);
t_status	find_node(t_util **pn, int fd);
t_status	init_string(t_string *ps);
char		*delete_current_node(t_util **pn);
t_eol		copy_static_to_string(t_util *curr, t_string *ps);
t_eol		memcpy_and_check_eol(char *dst, const char *src, size_t len);
char		*copy_string_to_ret_and_add_nul(t_string *ps, char *ret);
void		read_and_copy_static_to_string(t_util *curr, t_string *ps);
char		*delete_all_node(t_util **pn);
*/

#endif