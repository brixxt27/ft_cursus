/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:19:49 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "error.h"
#include <stdlib.h>

char	*parse_env(char **envp, char *target)
{
	int		i;
	char	*tmp;
	char	**words;

	i = 0;
	while (envp[i])
	{
		words = ft_split(envp[i], '=');
		err_catch(err_alloc, (long int)words);
		if (is_same(words[0], target))
		{
			tmp = words[1];
			free(words[0]);
			free(words);
			return (tmp);
		}
		free_words(words);
		i++;
	}
	return (NULL);
}
