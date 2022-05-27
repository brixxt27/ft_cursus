/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:51:59 by jayoon            #+#    #+#             */
<<<<<<< HEAD:ft_printf/ft_printf.h
/*   Updated: 2022/02/24 19:22:40 by jayoon           ###   ########.fr       */
=======
/*   Updated: 2022/02/26 23:51:32 by jayoon           ###   ########.fr       */
>>>>>>> 267c6c5f1bdeaf604d8ff71a559035ccc33dfd99:my_ft_printf/include/ft_printf.h
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

<<<<<<< HEAD:ft_printf/ft_printf.h
int		ft_printf(const char *format, ...);
int		ft_check_format(va_list ap, const char *str);
int		ft_is_format(char c);
void	ft_putchar_fd(char c, int fd);
=======
# define DECIMAL_BASE		"0123456789"
# define U_BASE_16			"0123456789ABCDEF"
# define L_BASE_16			"0123456789abcdef"

int	ft_case_upper_x(unsigned int num);
int	ft_case_c(char c);
int	ft_case_d_and_i(int num);
int	ft_case_p(void *ptr);
int	ft_case_percent(char c);
int	ft_case_s(char *str);
int	ft_case_u(unsigned int num);
int	ft_case_lower_x(unsigned int num);
int	ft_print_format(va_list ap, char c);
int	ft_printf(const char *format, ...);
>>>>>>> 267c6c5f1bdeaf604d8ff71a559035ccc33dfd99:my_ft_printf/include/ft_printf.h

#endif
