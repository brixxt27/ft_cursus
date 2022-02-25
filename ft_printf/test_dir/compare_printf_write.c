#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char	*str = "printf\n";

	printf("printf : %s", str);
	write(1, "write : write\n", 14);
	return (0);
}
