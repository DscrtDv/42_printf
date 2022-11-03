#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	res = ft_printf(" %X \n", 9223372036854775807LL);

	int d = printf(" %X \n", 9223372036854775807LL);

/*	int	re = ft_printf(" %x \n", INT_MIN );
	int sd = printf(" %x \n\n", INT_MIN);

	int	reds = ft_printf(" %x \n", LLONG_MIN );
	int dd = printf(" %x \n\n", LLONG_MIN);
*/

	printf("length of output: %d \n", res);
	printf("length of built in: %d \n", d);
//	printf("%lld \n", ULONG_MAX/16);
	return (0);
}
