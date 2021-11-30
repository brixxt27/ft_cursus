#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)

{

	printf("a int max 2147483647 : %d\n", atoi("2147483647"));

	printf("f int max 2147483647 : %d\n", ft_atoi("2147483647"));

	printf("a int min -2147483648 : %d\n", atoi("-2147483648"));

	printf("f int min -2147483648 : %d\n", ft_atoi("-2147483648"));

	printf("a int over 9999999999 : %d\n", atoi("9999999999"));

	printf("f int over 9999999999 : %d\n", ft_atoi("9999999999"));

	printf("a int under -9999999999 : %d\n", atoi("-9999999999"));

	printf("f int under -9999999999 : %d\n", ft_atoi("-9999999999"));

	printf("a long long plus 92233720368547758 : %d\n", atoi("92233720368547758"));

	printf("f long long plus 92233720368547758 : %d\n", ft_atoi("92233720368547758"));

	printf("a long long minus -92233720368547758 : %d\n", atoi("-92233720368547758"));

	printf("f long long minus -92233720368547758 : %d\n", ft_atoi("-92233720368547758"));

	printf("a long long max 9223372036854775807 : %d\n", atoi("9223372036854775807"));

	printf("f long long max 9223372036854775807 : %d\n", ft_atoi("9223372036854775807"));

	printf("a long long min -9223372036854775808 : %d\n", atoi("–9223372036854775808"));

	printf("f long long min -9223372036854775808 : %d\n", ft_atoi("–9223372036854775808"));

	printf("a long long max / 10 922337203685477580 : %d\n", atoi("922337203685477580"));

	printf("f long long max / 10 922337203685477580 : %d\n", ft_atoi("922337203685477580"));

	printf("a long long max / 10 + 1 922337203685477581 : %d\n", atoi("922337203685477581"));

	printf("f long long max / 10 + 1 922337203685477581 : %d\n", ft_atoi("922337203685477581"));

	printf("a long long max / 10 + 4 922337203685477584 : %d\n", atoi("922337203685477584"));

	printf("f long long max / 10 + 4 922337203685477584 : %d\n", ft_atoi("922337203685477584"));

	printf("a long long max / 10 + 5 922337203685477585 : %d\n", atoi("922337203685477585"));

	printf("f long long max / 10 + 5 922337203685477585 : %d\n", ft_atoi("922337203685477585"));

	printf("a long long max - 1 922337203685477586 : %d\n", atoi("922337203685477586"));

	printf("f long long max - 1 922337203685477586 : %d\n", ft_atoi("922337203685477586"));

	printf("a long long max + 1 9223372036854775808 : %d\n", atoi("9223372036854775808"));

	printf("f long long max + 1 9223372036854775808 : %d\n", ft_atoi("9223372036854775808"));

	printf("a long long max + 2 9223372036854775809 : %d\n", atoi("9223372036854775809"));

	printf("f long long max + 2 9223372036854775809 : %d\n", ft_atoi("9223372036854775809"));

	printf("a long long max + 10 9223372036854775817 : %d\n", atoi("9223372036854775817"));

	printf("f long long max + 10 9223372036854775817 : %d\n", ft_atoi("9223372036854775817"));

	printf("a long long min - 1 –9223372036854775809 : %d\n", atoi("–9223372036854775809"));

	printf("f long long min - 1 –9223372036854775809 : %d\n", ft_atoi("–9223372036854775809"));

	printf("a long long min - 2 –9223372036854775810 : %d\n", atoi("–9223372036854775810"));

	printf("f long long min - 2 –9223372036854775810 : %d\n", ft_atoi("–9223372036854775810"));

	printf("a long long min - 10 –9223372036854775818 : %d\n", atoi("–9223372036854775818"));

	printf("f long long min - 10 –9223372036854775818 : %d\n", ft_atoi("–9223372036854775818"));

	printf("a long long over 9223379876854775807 : %d\n", atoi("9223379876854775807"));

	printf("f long long over 9223379876854775807 : %d\n", ft_atoi("9223379876854775807"));

	printf("a long long under -9223379876854775807 : %d\n", atoi("-9223379876854775807"));

	printf("f long long under -9223379876854775807 : %d\n", ft_atoi("-9223379876854775807"));

	printf("a long long half 4611686018427387903 : %d\n", atoi("4611686018427387903"));

	printf("f long long half 4611686018427387903 : %d\n", ft_atoi("4611686018427387903"));

	printf("a zero 0 : %d\n", atoi("0"));

	printf("f zero 0 : %d\n", ft_atoi("0"));

	printf("a empty  : %d\n", atoi(""));

	printf("f empty  : %d\n", ft_atoi(""));

	return (0);

}
