/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:37:55 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 17:08:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC_H
# define PROC_H
# define BUFFER_SIZE 1024

typedef struct s_proc_info
{
	int		ch_num;
	char	*cmd;
	char	**envp;
	int		**pipes;
	int		max_fork;
}				t_proc_info;

void	proc_append_file(t_proc_info *info);
void	proc_write_file(t_proc_info *info);
void	proc_exe_cmd(t_proc_info *info);
void	proc_heredoc(t_proc_info *info);
void	proc_parent(t_proc_info *info);
void	proc_read_file(t_proc_info *info);
void	set_proc_child(int heredoc, void (**proc_child)(t_proc_info *));
void	wait_child(int n);

#endif
