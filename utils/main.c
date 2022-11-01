#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	//int res = ft_printf("Let's see / %c / %s / %% / %d / %i \n", 'c', "hello", 58, -258);
	//int d = printf("Let's see / %c / %s / %% / %d / %i \n", 'c', "hello", 58, -258);
	void *p;
	char *str;
	str = "ewbhu";
	p = str;
	int	res = ft_printf("trying hexa / %x / %X / %p \n", 264, 256, p);
	int d = printf("trying hexa / %x / %X / %p \n", 264, 256, p);

	printf("length of output: %d \n", res);
	printf("length oof built in: %d \n", d);
	return (0);
}
