/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:09:53 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 01:12:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"

void	safe_execve(char *pathname, char **argv, char **envp)
{
	int	err;

	err = execve(pathname, argv, envp);
	err_catch(err_execve, err);
}
