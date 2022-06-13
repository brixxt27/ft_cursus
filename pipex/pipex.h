/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/13 10:27:35 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	DEL_FIRST_CALL,
	DEL_YES,
	DEL_NO
}	t_delimeter;

// check error
void	check_error(t_error e, void *mem);
// libft.h
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *str, int	fd);

#endif
