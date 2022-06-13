#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    *str = "   ls -a   -l";
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
    i = 0;
    while (arr && arr[i])
    {
        free(arr[i++]);
    }
    free(arr);
    return (0);
}
