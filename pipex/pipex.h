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

char	**ft_split(char const *str, char c);

#endif
