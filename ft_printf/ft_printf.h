/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:51:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/16 19:02:36 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int     ft_printf(const char *format, ...);
int     ft_check_format(va_list ap, const char *str);
int     ft_is_format(char c);
void	ft_putchar_fd(char c, int fd);

#endif
