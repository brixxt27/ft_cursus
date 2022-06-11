#include <stdlib.h>
#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	while (str++)
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int	fd)
{
	write(fd, str, ft_strlen(str));
}

void	check_error(t_error e, void *mem)
{
	if (e == E_MALLOC && mem == 0)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
}

void	*allocate_memory(int size, int count)
{
	void	*mem;

	mem = malloc(size * count);
	check_error(E_MALLOC, (long int)mem);
	return (mem);
}

int		count_word(char const *str, char c)
{
	int	cnt;

	while (str)
	{
		if (*str == c)
			str++;
	}
}
char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		num_word;

	if (!str)
		return (NULL);
	num_word = count_word(str, c);
	ret = (char **)allocate_memory(sizeof(char *), num_word + 1);
	ret = put_word_in_ret(ret, str, num_word);
	// 이중 포인터에서 단일 포인터를 malloc 하던 도중에 실패하면 이미 할당해준 애들 전부 free 함수 필요
	return (ret);
}