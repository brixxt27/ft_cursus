/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:32:28 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 22:09:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_arguments(t_args *p_args, int argc, char **argv, char **envp)
{
	p_args->argc = argc;
	p_args->count_argc = argc - 3;
	p_args->argv = argv;
	p_args->envp = envp;
}
