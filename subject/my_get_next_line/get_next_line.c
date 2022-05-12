/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:03:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/01/29 19:50:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct s_gnl
{
	char		*str;
	static char	*saving;
}	t_gnl;

char	*get_next_line(int fd);
char	*read_and_save(int fd, char *saving);
char	*make_two_array_based_on_new_line(t_gnl *pset);
int		check_next_new_line(char *str);

char	*get_next_line(int fd)
{
	t_gnl	set;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	set.saving = read_and_save(fd, set.saving);
}
