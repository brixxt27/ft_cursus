#include <stdio.h>

int main(void)
{
    char    *str = "12345";
    char    *start;
    char    *end;

    start = &str[1];
    end = &str[2];
    printf("%ld\n", end - start);
    printf("end : %p, start : %p\n", end, start);
    return (0);
}