#include "pipex.h"
#include <stdio.h>

int main(void)
{
    char    *str = "ls -a -l";
    char    **arr;
    int     i;

    i = 0;
    arr = ft_split(str, ' ');
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
    return (0);
}