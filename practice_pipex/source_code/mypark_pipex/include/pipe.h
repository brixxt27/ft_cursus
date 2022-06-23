/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:50:33 by mypark            #+#    #+#             */
/*   Updated: 2022/03/03 14:01:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include "proc.h"

void	close_pipes(t_proc_info *info);
int		alloc_pipes(t_proc_info *info);
void	free_pipes(t_proc_info *info);

#endif
