/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:51:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/02/26 10:18:24 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define DECIMAL_BASE		"0123456789"
# define U_BASE_16			"0123456789ABCDEF"
# define L_BASE_16			"0123456789abcdef"

int ft_case_upper_x(unsigned int num);
int ft_case_c(char c);
int ft_case_d_and_i(int num);
int ft_case_p(void *ptr);
int ft_case_percent(char c);
int ft_case_s(char *str);
int ft_case_u(unsigned int num);
int ft_case_lower_x(unsigned int num);
int ft_is_format(char c);
int ft_print_format(va_list ap, char c);
int ft_printf(const char *format, ...);

#endif
