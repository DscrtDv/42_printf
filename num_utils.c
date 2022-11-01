#include "libft/libft.h"
#include "ft_printf.h"

static size_t	ulong_len (unsigned long n)
{
	size_t	len;
	
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*hex_converter(unsigned long n, char *set)
{
	size_t	len;
	char	*result;
	
	len = ulong_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (n)
	{
		result[len - 1] = set[n % 16];
		n /= 16;
		len--;
	}
	return (result);
}
