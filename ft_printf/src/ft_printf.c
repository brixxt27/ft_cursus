#include <stdarg.h>
#include "../libft/libft.h"

int	check_format(va_list ap, const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			if (is_)
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
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
	len = check_format(ap, format);
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	return (0);
}
*/
