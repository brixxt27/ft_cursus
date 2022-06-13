/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:42:17 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 01:11:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_H
# define SAFE_H
# include <stddef.h>

void	*safe_malloc(int size, int count);
int		safe_dup2(int from, int to);
int		safe_open(const char *file_name, int flags);
void	safe_pipe(int *arr);
void	safe_close(int fd);
void	safe_execve(char *pathname, char **argv, char **envp);
int		safe_read(int fd, const void *buf, size_t size);
int		safe_write(int fd, const void *buf, size_t size);

#endif
