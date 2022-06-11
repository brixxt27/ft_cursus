#ifndef PIPEX_H
# define PIPEX_H

// struct in main function
typedef struct s_list_of_main
{
	char	*path;
	char	**execve_argv;
}	t_list;

typedef enum e_list_of_error
{
	E_MALLOC
}	t_error;

// split
typedef enum e_is_delimeter
{
	DEL_YES,
	DEL_NO
}	t_delimeter;

// check error
void	check_error(t_error e, void *mem);
// libft.h
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int	fd);

#endif
