#include <stdio.h>

int main(void)
{
	char s[100];

	sprintf(s, "client: %d left\n", 5);
	printf("%s", s);
}