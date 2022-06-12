#include "pipex.h"
#include <stdio.h>

int main(void)
{
    char    *str = "         a";
    char    **arr;
    int     i;

    // printf("%zu\n", sizeof(str));
    // printf("%s", p);
    i = 0;
    arr = ft_split(str, ' ');
    while (arr && arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
    return (0);
}
