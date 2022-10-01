#include <stdarg.h>
#include <unistd.h>

#define BASE	"0123456789abcdef"

// util
static int	is_sdx(char c)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (1);
	return (0);
}

static int	ft_putstr(char *s)
{
	int	len = 0;

	while (*s)
	{
		len += write(1, s, 1);
		s++;
	}
	return (len);
}


// convert
static int	do_s(char *s)
{
	int	len;

	len = 0;
	len += ft_putstr(s);
	return (len);
}

static int	do_d(int num, int remain, int base)
{
	int	len;
	
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num != 0)
		len += do_d(num / base, num % base, 10);
	if (num != remain)
		len += write(1, &BASE[remain], 1);
	return (len);
}

static int	do_x(unsigned int num, unsigned int remain, int base)
{
	int	len;
	
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num != 0)
		len += do_d(num / base, num % base, 10);
	if (num != remain)
		len += write(1, &BASE[remain], 1);
	return (len);
}

static int	convert_char(va_list ap, char c)
{
	int		len;
	va_list	copy;

	len = 0;
	if (c == 's')
		len += do_s(va_arg(ap, char *));
	else if(c == 'd')
	{
		va_copy(copy, ap);
		len += do_d(va_arg(ap, int), va_arg(copy, int), 10);
	}
	else
	{
		va_copy(copy, ap);
		len += do_x(va_arg(ap, unsigned int), va_arg(copy, unsigned int), 16);
	}
	return (len);
}

static int	print_fmt(va_list ap, const char *fmt)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && is_sdx(fmt[++i]))
			len += convert_char(ap, fmt[i]);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ... )
{
	//s d x
	va_list	ap;
	int		len;

	va_start(ap, fmt);

	len = print_fmt(ap, fmt);

	va_end(ap);
	return (len);
}
