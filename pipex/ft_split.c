#include <stdlib.h>
#include "pipex.h"

char	**free_all_at_fail(char **ret, int i)
{
	while (i)
	{
		free(ret[i]);
		ret[i] = NULL;
		i--;
	}
	return (NULL);
}

char	*find_word_of_edge(char *curr, char c, char **start, char **end)
{
	t_delimeter	is_delimeter;

	is_delimeter = DEL_YES;
	*end = NULL;
	while (*curr == c)
		curr++;
	while (*curr && *end == NULL)
	{
		if (*curr == c || *curr == '\0')
		{
			*end = curr - 1;
			break ;
		}
		if (is_delimeter == DEL_YES)
			*start = curr;
		is_delimeter = DEL_NO;
		curr++;
	}
	if (*curr == '\0' && is_delimeter == DEL_NO)
		*end = curr -1;
	return (curr);
}

char	**make_ret(char **ret, char const *str, char c, int n)
{
	int		i;
	int		j;
	char	*start;
	char	*end;
	char	*curr;

	i = 0;
	curr = (char *)str;
	while (i < n)
	{
		j = 0;
		curr = find_word_of_edge(curr, c, &start, &end);
		ret[i] = (char *)malloc((end - start + 1) + 1);
		if (!ret[i])
			return (free_all_at_fail(ret, i));
		while (start <= end)
		{
			ret[i][j] = *start++;
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	return (ret);
}
int		count_word(char const *str, char c)
{
	int			cnt;
	t_delimeter	is_delimeter;

	cnt = 0;
	is_delimeter = DEL_YES;
	while (*str)
	{
		if (*str == c)
		{
			is_delimeter = DEL_YES;
			str++;
			continue ;
		}
		if (is_delimeter == DEL_YES)
			cnt++;
		is_delimeter = DEL_NO;
		str++;
	}
	return (cnt);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		num_word;

	if (!str)
		return (NULL);
	num_word = count_word(str, c);
	ret = malloc(sizeof(char *) * (num_word + 1));
	if (!ret)
		return (NULL);
	ret[num_word] = NULL;
	ret = make_ret(ret, str, c, num_word);
	return (ret);
}
