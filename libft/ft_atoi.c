#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int ft_atoi(const char *str)
{
	int					digit_len;
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	digit_len = ft_strlen(str);
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (digit_len > 19)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	if (res > LLONG_MAX + 1ULL && sign == -1)
		return (0);
	else if (res > LLONG_MAX && sign == 1)
		return (-1);
	return ((int)res * sign);
}
