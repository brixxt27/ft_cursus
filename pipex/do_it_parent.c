/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:55:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/18 22:01:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	close_file(t_files *p_files)
{
	int	ret;
	
	ret = close(p_files->input_fd);
	check_error(E_SYSTEM_CALL, (long long)ret);
}

void	do_it_parent(t_files *p_files)
{
	close_file(p_files);
}
