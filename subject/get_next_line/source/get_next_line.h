/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:59:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/01 22:26:12 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_util
{
	int				fd;
	char			buf[BUFFER_SIZE];
	ssize_t			index;
	ssize_t			ret_read;
	struct s_util	*next;
}	t_util;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	malloc_size;
}	t_string;

typedef enum e_util_of_status
{
	SUCCESS = 0,
	FAIL,
	EXIST,
	NOT_EXIST,
	MALLOC_ERROR
}	t_stat;

char	*get_next_line(int fd);
t_stat	copy_buffer_to_string(t_util *curr, t_string *ps);
char	*make_return(int fd, t_util *head, t_util **phead, t_string *ps);
t_stat	read_and_copy_to_str(int fd, t_util *curr, t_string *ps);

t_stat	find_node(int fd, t_util **phead, t_util **pcurr);
t_stat	init_string(t_string *ps);
char	*delete_current_node(int fd, t_util *head, t_util **phead);
char	*free_string(t_string *ps);
t_stat	stretch_string(t_string *ps);

#endif
