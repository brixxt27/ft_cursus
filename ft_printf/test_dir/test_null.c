#include <stdio.h>

int main(void)
{
	int	len;

	len = printf("%s\n", NULL);
	printf("len : %d\n", len);
}
