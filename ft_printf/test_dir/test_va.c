#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	ret_len(char *s, ...)
{
	int 	len;
	va_list	ap;

	len = 0;
	va_start(ap, s);
	printf("d : %d\n", va_arg(ap, int));	
	len = strlen(s);
	va_end(ap);
	return (len);
}

int 	main(void)
{
	char	*s = "123456";
	int		n1 = 42;
	char	c = 'A';
	int		n2 = 0x10;
	int		len = 0;

	len = ret_len(s, n1 + 0x10, n2, c);
	printf("Lenth is %d\n", len);
	return (0);
}
