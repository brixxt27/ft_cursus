/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:21:51 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 17:19:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error
{
	err_alloc,
	err_open,
	err_close,
	err_access,
	err_pipe,
	err_dup,
	err_execve,
	err_wait,
	err_write,
	err_read
};

void	err_catch(enum e_error e, int ret);
void	err_catch_fork(int ret, int ch_num);

#endif
