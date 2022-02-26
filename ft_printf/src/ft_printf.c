#include <stdarg.h>
#include "../include/ft_printf.h"

static int	ft_check_format(va_list ap, const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += ft_putchar_fd(*str, 1);
		else if (*str == '%' && *(str + 1))
		{
			str++;
			if (ft_is_format(*str))
				len += ft_print_format(ap, *str);
			else
				len += ft_putchar_fd(*str, 1);
		}
		str++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (0);
	va_start(ap, format);
	len = ft_check_format(ap, format);
	va_end(ap);
	return (len);
}
