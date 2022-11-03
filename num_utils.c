#include "libft/libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>

static size_t	ulong_len(long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		//printf("Here you go %llu/ %d \n", n, base);
		n /= (unsigned long) base;
		//printf("%zu, %llu / %d \n", len, n, base);
		len++;
	}
//	printf("Len of num: %zu \n", len);
	return (len);
}

char	*unsigned_itoabase(long long n, char *set, int base)
{
	size_t	len;
	char	*result;
	//printf(" n is: %llu \n", n);	
	len = ulong_len(n, base);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	result[len] = '\0';
	while (n)
	{
		result[len - 1] = set[(unsigned)n % base];
	//	printf("/%i at index %zu expected %c for %lld \n", result[len - 1], len - 1, set[n%base], n);
		n /= (unsigned long)base;
		len--;
	}
	//printf("%s \n", result);
	return (result);
}
